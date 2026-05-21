//Floyd(多源最短路)
for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
        if (i == j) map[i][j] = 0;
        else map[i][j] = INF;
    }
}
void Floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
}