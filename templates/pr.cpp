//Pollard-Rho
ll max_factor;
inline ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
inline ll qp(ll x, ll p, ll mod) {
    ll ans = 1;
    while (p) {
        if (p & 1)
            ans = (ii)ans * x % mod;
        x = (ii)x * x % mod;
        p >>= 1;
    }
    return ans;
}
inline bool mr(ll x, ll b) {
    ll k = x - 1;
    while (k) {
        ll cur = qp(b, k, x);
        if (cur != 1 && cur != x - 1)
            return false;
        if ((k & 1) == 1 || cur == x - 1)
            return true;
        k >>= 1;
    }
    return true;
}
inline bool prime(ll x) {
    if (x == 46856248255981ll || x < 2)
        return false;
    if (x == 2 || x == 3 || x == 7 || x == 61 || x == 24251)
        return true;
    return mr(x, 2) && mr(x, 61);
}
inline ll f(ll x, ll c, ll n) {
    return ((ii)x * x + c) % n;
}
inline ll PR(ll x) {
    ll s = 0, t = 0, c = 1ll * rand() % (x - 1) + 1;
    int stp = 0, goal = 1;
    ll val = 1;
    for (goal = 1;; goal <<= 1, s = t, val = 1) {
        for (stp = 1; stp <= goal; ++stp) {
            t = f(t, c, x);
            val = (ii)val * abs(t - s) % x;
            if ((stp % 127) == 0) {
                ll d = gcd(val, x);
                if (d > 1)
                    return d;
            }
        }
        ll d = gcd(val, x);
        if (d > 1)
            return d;
    }
}
inline void fac(ll x) {
    if (x <= max_factor || x < 2)
        return;
    if (prime(x)) {
        max_factor = max_factor > x ? max_factor : x;
        return;
    }
    ll p = x;
    while (p >= x)
        p = PR(x);
    while ((x % p) == 0)
        x /= p;
    fac(x), fac(p);
}
int main() {
    srand((unsigned)time(NULL));
    max_factor = 0; //质因子
    fac(n);
}