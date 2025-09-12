param (
    [switch]$Recursive,
    [string[]]$Directories = @()
)

# Create a function to process a single directory
function Process-Directory {
    param (
        [string]$CurrentDir
    )
    
    $OutputFile = Join-Path -Path $CurrentDir -ChildPath 'config.yml'
    
    # Clear or create the config.yml file
    "contents:" | Set-Content -Path $OutputFile -Encoding utf8

    # Create a hashtable to track processed files
    $ProcessedFiles = @{}

    # Iterate through the current directory and files
    Get-ChildItem -Path $CurrentDir | ForEach-Object {
        $Entry = $_
        
        if ($Entry.PSIsContainer) {
            # Process subdirectories
            $DirName = $Entry.Name
            Add-Content -Path $OutputFile -Value "  - name: $DirName"
            Add-Content -Path $OutputFile -Value "    directory: $DirName"
            
            # If recursive is enabled, recursively call the function for subdirectories
            if ($Recursive) {
                Process-Directory -CurrentDir $Entry.FullName
            }
        } elseif (-not ($Entry.Name -eq 'config.yml')) {
            $BaseName = $null

            # Check file type and get base name
            if ($Entry.Name -like '*.cpp') {
                $BaseName = $Entry.BaseName
            } elseif ($Entry.Name -like '*.java') {
                $BaseName = $Entry.BaseName
            } elseif ($Entry.Name -like '*.py') {
                $BaseName = $Entry.BaseName
            } elseif ($Entry.Name -like '*-pre.tex') {
                $BaseName = $Entry.BaseName -replace '-pre$', ''
            } elseif ($Entry.Name -like '*-post.tex') {
                $BaseName = $Entry.BaseName -replace '-post$', ''
            } else {
                Write-Host "Unrecognized file: ${Entry}"
                return  # Skip other irrelevant files
            }

            if ($null -ne $BaseName -and -not $ProcessedFiles.ContainsKey($BaseName)) {
                # Mark as processed
                $ProcessedFiles[$BaseName] = $true

                # Start entry
                Add-Content -Path $OutputFile -Value "  - name: $BaseName"

                # Collect codes (cpp/java/py)
                Add-Content -Path $OutputFile -Value "    codes:"

                if (Test-Path (Join-Path -Path $CurrentDir -ChildPath "$BaseName.cpp")) {
                    Add-Content -Path $OutputFile -Value "      - $BaseName.cpp"
                }
                if (Test-Path (Join-Path -Path $CurrentDir -ChildPath "$BaseName.java")) {
                    Add-Content -Path $OutputFile -Value "      - $BaseName.java"
                }
                if (Test-Path (Join-Path -Path $CurrentDir -ChildPath "$BaseName.py")) {
                    Add-Content -Path $OutputFile -Value "      - $BaseName.py"
                }

                # Process pre-code and post-code files
                if (Test-Path (Join-Path -Path $CurrentDir -ChildPath "$BaseName-pre.tex")) {
                    Add-Content -Path $OutputFile -Value "    code-pre: $BaseName-pre.tex"
                }
                if (Test-Path (Join-Path -Path $CurrentDir -ChildPath "$BaseName-post.tex")) {
                    Add-Content -Path $OutputFile -Value "    code-post: $BaseName-post.tex"
                }
            }
        }
    }

    Write-Host "Generated config.yml file at: $OutputFile"
}

foreach ($Dir in $Directories) {
    if (Test-Path -Path $Dir -PathType Container) {
        Process-Directory -CurrentDir $Dir
    } else {
        Write-Warning "${Dir} is not a valid directory, skipping processing."
    }
}