//st表
void pre(int maxn) {
    Logn[1] = 0;
    Logn[2] = 1;
    for (int i = 3; i <= maxn; i++) {
        Logn[i] = Logn[i / 2] + 1;
    }
}
ll query(int L, int R) {
    int k = Logn[R - L + 1];
    return min(st[L][k], st[R - (1 << k) + 1][k]);
}
for (int i = 1; i <= n; ++i) st[i][0] = a[i];
for (int i = 1; i <= Logn[n]; ++i) {
    for (int j = 1; j + (1ll << (i - 1)) - 1 <= n; ++j) {
        st[j][i] = max(st[j][i - 1], st[j + (1ll << (i - 1))][i - 1]);
    }
}
while (m--) {
    ll l, r;
    cin >> l >> r;
    ll mid = Logn[r - l + 1];
    ll ans = max(st[l][mid], st[r - (1ll << mid) + 1][mid]);
    cout << ans << endl;
}