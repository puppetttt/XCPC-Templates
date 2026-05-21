void GetPrime(int n) {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i])
            Prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * Prime[j] <= n; j++) {
            isPrime[i * Prime[j]] = 0;
            if (i % Prime[j] == 0)
                break;
        }
    }
}