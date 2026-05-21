//拓扑排序(有向无环)
int d[N];//d记录的是每个点初始态的入度
void TopoSort() {
    queue<int>q;
    for (int i = 1; i <= n; ++i) {
        if (d[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = edge[i].next) {
            d[edge[i].to]--;
            if (d[edge[i].to] == 0) {
                q.push(edge[i].to);
            }
        }
    }
}