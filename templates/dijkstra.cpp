ll dis[1000006];
ll used[1000006];
void Dijkstra() {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater< pair<ll, ll> > > q;
    q.push({0, s});
    while (!q.empty()) {
        ll x = q.top().second;
        q.pop();
        if (used[x]) continue;
        used[x] = true;
        for (int i = head[x]; i; i = edge[i].next) {
            ll y = edge[i].to;
            ll z = edge[i].wei;
            if (!used[y] && dis[y] > dis[x] + z) {
                dis[y] = dis[x] + z;
                q.push({dis[y], y});
            }
        }
    }
}
memset(dis, 0x3f, sizeof(dis));
dis[1] = 0;