ll fact[N], infact[N];
ll qmi(ll a, ll k, ll p) {
    ll res = 1 % p;
    while (k) {
        if (k & 1) res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}
ll C(ll a, ll b) {
    if (a == b || b == 0 || b > a)return 1;
    return fact[a] * infact[a - b] % MOD * infact[b] % MOD;
}
int main() {
    fact[0] = infact[0] = 1;
    for (ll i = 1 ; i <= n; ++i) {
        fact[i] = (ll)fact[i - 1] * i % MOD;
        //infact[i] = (ll)infact[i - 1] * qmi(i, MOD - 2, MOD) % MOD;
    }
    infact[n] = qmi(fact[n], MOD - 2, MOD) % MOD;
    for (ll i = n - 1; i >= 1; i--) {
        infact[i] = infact[i + 1] * (i + 1) % MOD;
    }
}