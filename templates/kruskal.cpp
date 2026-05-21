int Find(int x) {
    int root = x;
    while (S[root] >= 0) root = S[root];
    while (x != root) {
        int temp = S[x];
        S[x] = root;
        x = temp;
    }
    return root;
}
void Union(int root1, int root2) {
    if (root1 == root2) return;
    S[root1] = root2;
}
bool cmp(EDGE a, EDGE b) {
    return a.wei < b.wei;
}
void Kruskal() {
    sort(edge, edge + m, cmp);
    for (int i = 1; i <= m; ++i) {
        eu = Find(edge[i].u), ev = Find(edge[i].v);
        if (eu == ev) {
            continue;
        }
        ans += edge[i].w;
        Union(eu, ev);
        cnt++;
        if (cnt == n - 1) break;
    }
}