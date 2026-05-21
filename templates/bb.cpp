//01背包
for (int i = 1; i <= m; ++i) {
    for (int j = t; j >= 0; --j) {
        if (j - ti[i] < 0) break;
        dp[j] = max(dp[j], dp[j - ti[i]] + value[i]);
    }
}
//完全01背包
for (int i = 1; i <= m; ++i) {
    for (int j = ti[i]; j <= n; j++) {
        dp[j] = max(dp[j] , dp[j - ti[i]] + value[i]) ;
    }
}
//分组背包
ll dp[2][303];
memset(dp, -0x3f, sizeof(dp));
cin >> n >> x; //代表装备数量和小红初始拥有的金币
dp[0][0] = 0; //前几件花多少钱
for (ll i = 1; i <= n; ++i) {
    ll a, b, c, d, e; //分别代表装备初始战力，购买该装备需要的金币、升1级花费的金币、升1级提升的战力、最高可以提升的等级
    cin >> a >> b >> c >> d >> e;
    for (ll j = 0; j <= x; ++j) dp[1][j] = dp[0][j]; //什么都不干
    for (ll j = 0; j <= x; ++j) { //花的钱数
        for (ll k = 0; k <= e; ++k) { //生几次级
            if (k * c + b > j) break; //超出钱的限制
            dp[1][j] = max(dp[1][j], dp[0][j - (k * c + b)] + k * d + a);
            ans = max(ans, dp[1][j]);
        }
    }
    for (ll j = 0; j <= x; ++j) dp[0][j] = dp[1][j]; //滚动优化
}