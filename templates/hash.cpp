const int B = 131;
ull hash1[N];
ull hash2[N];
ull X[N];
ull js(char a) {
    return (ull) (a - 'a');
}
ull gethash(int Hash[], int left, int right) {
    return left ? Hash[right] - Hash[left - 1] * X[right - left] : Hash[right];
}
X[0] = B;
hash1[0] = (ull)js(s[0]);
for (int i = 1; i < n; ++i) {
    hash1[i] = hash1[i - 1] * B + (ull)js(s[i]);
    X[i] = X[i - 1] * B;
}
hash2[0] = (ull)js(s[n - 1]);
for (int j = n - 2; j >= 0; --j) {
    hash2[n - j - 1] = hash2[n - j - 2] * B + (ull)js(s[j]);
}
while (q--) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    ll mid = (x + y) >> 1;
    if (gethash(hash1, x, mid) == gethash(hash2, n - y - 1, n - mid - 1))
    }
//处理回文为偶数，每两个字符中间插入一个没出现过的字符
for (int i = n * 2; i > 0; i -= 2) {
    s[i] = s[i / 2];
    s[i - 2] = 'z' + 1;
}