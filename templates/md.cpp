//莫队
int aa[N], cnt[N], belong[N];
int n, m, size, bnum, now, ans[N];
struct query {
    int l, r, id;
} q[N];
int cmp(query a, query b) {
    return (belong[a.l] ^ belong[b.l]) ? belong[a.l] < belong[b.l] : ((belong[a.l] & 1) ? a.r < b.r : a.r > b.r);
}
int main() {
    cin >> n;
    size = sqrt(n);
    bnum = ceil((double)n / size);
    for (int i = 1; i <= bnum; ++i)
        for (int j = (i - 1) * size + 1; j <= i * size; ++j) {
            belong[j] = i;
        }
    for (int i = 1; i <= n; ++i) cin >> aa[i];
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + m + 1, cmp);
    int l = 1, r = 0;
    for (int i = 1; i <= m; ++i) {
        int ql = q[i].l, qr = q[i].r;
        while (l < ql) now -= !--cnt[aa[l++]];
        while (l > ql) now += !cnt[aa[--l]]++;
        while (r < qr) now += !cnt[aa[++r]]++;
        while (r > qr) now -= !--cnt[aa[r--]];
        ans[q[i].id] = now;
    }
    for (int i = 1; i <= m; ++i) cout << ans[i] << endl;
}
//带修莫队
int a[N], cnt[N], ans[N], belong[N];
struct query {
    int l, r, time, id;
} q[N];
struct modify {
    int pos, color, last;
} c[N];
int cntq, cntc, n, m, size, bnum;
int cmp(query a, query b) {
    return (belong[a.l] ^ belong[b.l]) ? belong[a.l] < belong[b.l] : ((belong[a.r] ^ belong[b.r]) ? belong[a.r] < belong[b.r] : a.time < b.time);
}
int main() {
    cin >> n >> m;
    size = pow(n, 2.0 / 3.0);
    bnum = ceil((double)n / size);
    for (int i = 1; i <= bnum; ++i)
        for (int j = (i - 1) * size + 1; j <= i * size; ++j) {
            belong[j] = i;
        }
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) {
        char opt;
        cin >> opt;
        if (opt == 'Q') {
            cin >> q[++cntq].l >> q[cntq].r;
            q[cntq].time = cntc;
            q[cntq].id = cntq;
        }
        else if (opt == 'R') {
            cin >> c[++cntc].pos >> c[cntc].color;
        }
    }
    sort(q + 1, q + cntq + 1, cmp);
    int l = 1, r = 0, time = 0, now = 0;
    for (int i = 1; i <= cntq; ++i) {
        int ql = q[i].l, qr = q[i].r, qt = q[i].time;
        while (l < ql) now -= !--cnt[a[l++]];
        while (l > ql) now += !cnt[a[--l]]++;
        while (r < qr) now += !cnt[a[++r]]++;
        while (r > qr) now -= !--cnt[a[r--]];
        while (time < qt) {
            ++time;
            if (ql <= c[time].pos && c[time].pos <= qr) now -= !--cnt[a[c[time].pos]] - !cnt[c[time].color]++;
            swap(a[c[time].pos], c[time].color);
        }
        while (time > qt) {
            if (ql <= c[time].pos && c[time].pos <= qr) now -= !--cnt[a[c[time].pos]] - !cnt[c[time].color]++;
            swap(a[c[time].pos], c[time].color);
            --time;
        }
        ans[q[i].id] = now;
    }
    for (int i = 1; i <= cntq; ++i) cout << ans[i] << endl;
    return 0;
}