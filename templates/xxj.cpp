//线性基(在数中选取任意个，使得他们的异或和最大(最小)(第k小))
ll p[N];
ll flag = false;
void upd(ll x) {
    for (int i = 60; i >= 0; --i) {
        if ((x >> i) & 1) {
            if (!p[i]) {p[i] = x; break;}
            x ^= p[i];
        }
    }
    flag = true;
}
bool check(ll x) {
    for (int i = 60; i >= 0; --i) {
        if (x & (1ll << i)) {
            if (!p[i])return false;
            else x ^= p[i];
        }
    }
    return true;
}
ll getmin() {
    if (flag)return 0;
    for (int i = 0; i <= 60; ++i)
        if (p[i]) return p[i];
}
ll getmax() {
    ll ans = 0;
    for (int i = 60; i >= 0; --i) {
        if ((ans ^ p[i]) > ans) ans ^= p[i];
    }
    return ans;
}
void prework() {
    for (int i = 1; i <= 60; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (p[i] & (1LL << j - 1)) p[i] ^= p[j - 1];
        }
    }
}
inline ll getkth(int k) {
    if (k == 1 && size < n) return 0;
    if (size < n) --k;
    //n表示序列长度，size表示线性基内部元素个数
    prework();
    ll ans = 0;
    for (int i = 0; i <= 60; ++i) {
        if (p[i]) {
            if (k & 1) ans ^= p[i];
            k >>= 1;
        }
    }
    return ans;
}