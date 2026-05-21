//树状数组
int lowbit(int k) {
    return k & -k;
}
for (int i = 1; i <= n; ++i) {
    ll a;
    cin >> a;
    add(i, a);
}
void add(int x, int k) { //单点修改
    while (x <= n) {
        tree[x] += k;
        x += lowbit(x);
    }
}
ll query(int x) { //单点查询
    int ans = 0;
    while (x != 0) {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}