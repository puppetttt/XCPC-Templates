//tarjan
ll head[500005];
ll cnt;
ll tot;
ll sc;
ll dfn[N];
ll low[N];
vector<ll>scc[N];
ll in[N];
stack<ll>st;
ll k;
ll c[N];//c[k]表示k属于哪个强连通分量内
struct EDGE {
    int next;
    int to;
} edge[500005];
void add(int x, int y) {
    cnt++;
    edge[cnt].next = head[x];
    edge[cnt].to = y;
    head[x] = cnt;
}
void tarjan(int x) {
    tot++;
    dfn[x] = low[x] = tot;
    in[x] = 1;
    st.push(x);
    for (int i = head[x]; i; i = edge[i].next) {
        if (dfn[edge[i].to] == 0) {
            tarjan(edge[i].to);
            low[x] = min(low[x], low[edge[i].to]);
        }
        else if (in[edge[i].to]) {
            low[x] = min(low[x], dfn[edge[i].to]);
        }
    }
    if (dfn[x] == low[x]) {
        sc++;
        while (x != k) {
            k = st.top();
            in[k] = 0;
            c[k] = sc;
            scc[sc].pb(k);
            st.pop();
        }
    }
}
// 缩点
ll u[N];
ll v[N];
if (dfn[x] == low[x]) {
    sc++;
    while (x != k) {
        k = st.top();
        in[k] = 0;
        c[k] = sc;
        //scc[sc].pb(k);
        b[sc] += a[k]; //a[]为原点权，b[]为缩点后的点权
        st.pop();
    }
}
for (int i = 1; i <= cnt; ++i) {
    head[i] = 0;
    edge[i].next = 0;
    edge[i].to = 0;
}
tot = 0;
cnt = 0;
for (int i = 1; i <= m; ++i) {
    if (c[u[i]] != c[v[i]]) {
        add(c[u[i]], c[v[i]]);
    }
}
//割点
void tarjan(int x, int fa) {
    tot++;
    dfn[x] = low[x] = tot;
    in[x] = 1;
    ll son = 0;
    st.push(x);
    for (int i = head[x]; i; i = edge[i].next) {
        if (dfn[edge[i].to] == 0) {
            tarjan(edge[i].to, fa);
            low[x] = min(low[x], low[edge[i].to]);
            if (low[edge[i].to] >= dfn[x]) {
                son++;
                if (x != fa || son >= 2) {
                    s.insert(x);
                }
            }
        }
        else  {
            low[x] = min(low[x], dfn[edge[i].to]);
        }
    }
    if (dfn[x] == low[x]) {
        sc++;
        while (x != k) {
            k = st.top();
            in[k] = 0;
            c[k] = sc;
            st.pop();
        }
    }
}
for (int i = 1; i <= n; ++i) {
    if (dfn[i] == 0) {
        tarjan(i, i);
    }
}
//割边
//建图时边的编号从 2 开始标，能以O1的复杂度求出某边的逆向边（异或运算），并且标记割边。
cnt = 1;
void tarjan(int x, int fa) {
    tot++;
    dfn[x] = low[x] = tot;
    for (int i = head[x]; i; i = edge[i].next) {
        if (dfn[edge[i].to] == 0) {
            tarjan(edge[i].to, i);
            low[x] = min(low[x], low[edge[i].to]);
            if (low[edge[i].to] > dfn[x]) {
                edge[i].flag = edge[i ^ 1].flag = true;
            }
        }
        else if ((fa ^ 1) != i) {
            low[x] = min(low[x], dfn[edge[i].to]);
        }
    }
}
for (int i = 1; i <= n; ++i) {
    if (dfn[i] == 0) {
        tarjan(i, 0);
    }
}
//点双联通分量
vector<ll>dcc[N];
void tarjan(int x, int fa) {
    if (x == fa && head[x] == 0) { //孤立点判定
        ans++;
        dcc[ans].pb(x);
    }
    tot++;
    dfn[x] = low[x] = tot;
    st.push(x);
    for (int i = head[x]; i; i = edge[i].next) {
        if (dfn[edge[i].to] == 0) {
            tarjan(edge[i].to, fa);
            low[x] = min(low[x], low[edge[i].to]);
            if (low[edge[i].to] >= dfn[x]) {
                ans++;
                dcc[ans].pb(x);
                while (edge[i].to != k) {
                    k = st.top();
                    dcc[ans].pb(k);
                    st.pop();
                }
            }
        }
        else {
            low[x] = min(low[x], dfn[edge[i].to]);
        }
    }
}
for (int i = 1; i <= m; ++i) {
    cin >> u[i] >> v[i];
    if (u[i] != v[i]) {
        add(u[i], v[i]);
        add(v[i], u[i]);
    }
}
for (int i = 1; i <= n; ++i) {
    if (dfn[i] == 0) {
        tarjan(i, i);
    }
}
//边双联通分量
cnt = 1;
void tarjan(int x, int fa) {
    tot++;
    dfn[x] = low[x] = tot;
    st.push(x);
    for (int i = head[x]; i; i = edge[i].next) {
        if (dfn[edge[i].to] == 0) {
            tarjan(edge[i].to, i);
            low[x] = min(low[x], low[edge[i].to]);
            if (low[edge[i].to] > dfn[x]) {
                edge[i].flag = edge[i ^ 1].flag = true;
            }
        }
        else if ((fa ^ 1) != i) {
            low[x] = min(low[x], dfn[edge[i].to]);
        }
    }
    if (low[x] == dfn[x]) {
        sc++;
        while (x != k) {
            k = st.top();
            dcc[sc].pb(k);
            st.pop();
        }
    }
}