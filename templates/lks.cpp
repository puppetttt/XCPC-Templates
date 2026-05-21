ll qmi(ll a, ll k, ll p) {
    ll res = 1 % p;
    while (k) {
        if (k & 1) res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}
ll C(ll a, ll b, ll p) {
    if (b > a) return 0;
    ll res = 1;
    for (ll i = 1, j = a; i <= b; ++i, --j) {
        res = (ll)res * j % p;
        res = (ll)res * qmi(i, p - 2, p) % p;
    }
    return res;
}
ll lucas(ll a, ll b, ll p) {               // 注意LL参数类型
    if (a < p && b < p) return C(a, b, p);
    return (ll)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;     // 递归让其到p范围内求解
}