//树链剖分
ll a[N];
ll n;
ll fa[N];
ll deep[N];
ll son[N];
ll siz[N];
ll seg[N];
ll top[N];
ll dfn[N];
ll cnt;
vector<ll>e[N];
struct node {
    int l, r;
    ll pre, cheng, jia;
} tree[N << 2];
void build(int index, int left, int right) {
    tree[index].l = left;
    tree[index].r = right;
    tree[index].cheng = 1 % MOD;
    tree[index].jia = 0;
    if (left == right) {
        tree[index].pre = a[seg[left]] % MOD;
        return;
    }
    int mid = (right + left) >> 1;
    ll pos = index << 1;
    ll pos1 = pos | 1;
    build(pos, left, mid);
    build(pos1, mid + 1, right);
    tree[index].pre = (tree[pos].pre + tree[pos1].pre) % MOD;
}
void spread(int index) {
    ll pos = index << 1;
    ll pos1 = pos | 1;
    tree[pos].jia = (tree[pos].jia * tree[index].cheng % MOD + tree[index].jia) % MOD;
    tree[pos1].jia = (tree[pos1].jia * tree[index].cheng % MOD + tree[index].jia) % MOD;
    tree[pos].cheng = (tree[pos].cheng * tree[index].cheng) % MOD;
    tree[pos1].cheng = (tree[pos1].cheng * tree[index].cheng) % MOD;
    tree[pos].pre = (tree[index].jia * (tree[pos].r - tree[pos].l + 1) % MOD + tree[pos].pre * tree[index].cheng % MOD) % MOD;
    tree[pos1].pre = (tree[index].jia * (tree[pos1].r - tree[pos1].l + 1) % MOD + tree[pos1].pre * tree[index].cheng % MOD) % MOD;
    tree[index].cheng = 1;
    tree[index].jia = 0;
}
ll query(int index, int l, int r, int left, int right) {
    if (l >= left && r <= right) {
        return tree[index].pre % MOD;
    }
    spread(index);
    ll ans = 0;
    ll pos = index << 1;
    ll pos1 = pos | 1;
    if (tree[pos].r >= left)
        ans = (ans + query(pos, tree[pos].l, tree[pos].r, left, right)) % MOD;
    if (tree[pos1].l <= right)
        ans = (ans + query(pos1, tree[pos1].l, tree[pos1].r, left, right)) % MOD;
    return ans;
}
void update_cheng(int index, int l, int r, int left, int right, ll k) {
    if (l >= left && r <= right) {
        tree[index].pre = tree[index].pre * k % MOD;
        tree[index].cheng = tree[index].cheng * k % MOD;
        tree[index].jia = tree[index].jia * k % MOD;
        return ;
    }
    spread(index);
    ll pos = index << 1;
    ll pos1 = pos | 1;
    if (tree[pos].r >= left)
        update_cheng(pos, tree[pos].l , tree[pos].r, left, right, k);
    if (tree[pos1].l <= right)
        update_cheng(pos1, tree[pos1].l , tree[pos1].r, left, right, k);
    tree[index].pre = (tree[pos].pre + tree[pos1].pre) % MOD;
}
void update_jia(int index, int l, int r, int left, int right, ll k) {
    if (l >= left && r <= right) {
        tree[index].pre = (tree[index].pre + k * (r - l + 1) % MOD) % MOD;
        tree[index].jia = (tree[index].jia + k) % MOD;
        return ;
    }
    spread(index);
    ll pos = index << 1;
    ll pos1 = pos | 1;
    if (tree[pos].r >= left)
        update_jia(pos, tree[pos].l , tree[pos].r, left, right, k);
    if (tree[pos1].l <= right)
        update_jia(pos1, tree[pos1].l , tree[pos1].r, left, right, k);
    tree[index].pre = (tree[pos].pre + tree[pos1].pre) % MOD;
}
void dfs1(int u, int f) {
    deep[u] = deep[f] + 1;
    fa[u] = f;
    siz[u] = 1;
    son[u] = 0;
    ll maxx = 0;
    for (auto v : e[u]) {
        if (v == f) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[v] > maxx) {
            maxx = siz[v];
            son[u] = v;
        }
    }
}
void dfs2(int u, int topf) {
    dfn[u] = ++cnt;
    seg[cnt] = u;
    top[u] = topf;
    if (!son[u]) return;
    dfs2(son[u], topf);
    for (auto v : e[u]) {
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}
ll query_range(int x, int y) {
    ll ans = 0;
    while (top[x] != top[y]) {
        if (deep[top[x]] < deep[top[y]]) swap(x, y);
        ll res = query(1, 1, n, dfn[top[x]], dfn[x]);
        ans = (ans + res) % MOD;
        x = fa[top[x]];
    }
    if (deep[x] > deep[y])swap(x, y);
    ll res = query(1, 1, n, dfn[x], dfn[y]);
    ans = (ans + res) % MOD;
    return ans;
}
ll query_son(int x) {
    ll res = query(1, 1, n, dfn[x], dfn[x] + siz[x] - 1);
    return res;
}
void upd_range(int x, int y, ll k) {
    while (top[x] != top[y]) {
        if (deep[top[x]] < deep[top[y]])swap(x, y);
        update_jia(1, 1, n, dfn[top[x]], dfn[x], k);
        x = fa[top[x]];
    }
    if (deep[x] > deep[y])swap(x, y);
    update_jia(1, 1, n, dfn[x], dfn[y], k);
}
void upd_son(int x, ll k) {
    update_jia(1, 1, n, dfn[x], dfn[x] + siz[x] - 1, k);
}
ll lca(int x, int y) {
    while (top[x] != top[y]) {
        if (deep[top[x]] < deep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return dfn[x] <= dfn[y] ? x : y;
}