//二分图
bool dfs(int u, int cl) {
    col[u] = cl;
    for (auto v : g[u]) {
        if (!col[v] && !dfs(v, 3 - cl)) return 0;
        else if (col[v] == cl) return 0;
    }
    return 1;
}