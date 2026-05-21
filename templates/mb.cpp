inline int lcm(int GCD, int n, int m) {return n * m / GCD;}
inline int gcd(int x, int y) {return y ? gcd(y, x % y) : x;}
random_device rd; mt19937 rnd(rd());
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
inline int rand(int l, int r) {return uniform_int_distribution<int>(l, r)(rnd);}
//Dilworth定理
//求一个数列的最长不上升子序列的长度和最优经过几次最长不上升子序列的覆盖可以覆盖完整个数列。
//对于一个偏序集，最少链划分等于最长反链长度。在这道题中：
//最长上升子序列的长度就是能构成的不上升序列的个数。
//setprecision  next_permutation nth_element(a+1,a+pos,a+1+n)
ll roundd(long double n) {
	return n - (ll)n >= 0.5 ? (ll)n + 1 : (ll)n;
}
auto solve = [&](auto self, ll a, ll b)->void{
};
//删除重复元素
sort(edge.begin(), edge.end());
edge[i].erase(unique(edge.begin(), edge.end()), edge.end());
sort(a + 1, a + 1 + n);
int q = unique(a + 1, a + n + 1) - a - 1; //删除后的长度
//线性求一串数字对于mod p的逆元
inv[1] = 1;
for (int i = 2; i <= n; ++ i) {
	inv[i] = (p - p / i) * inv[p % i] % p;
}