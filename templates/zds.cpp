//字典树
int trie[3000005][65], cnt[3000005], idx;
int getnum(char x) { //映射字符
    if (x >= 'A' && x <= 'Z')
        return x - 'A';
    else if (x >= 'a' && x <= 'z')
        return x - 'a' + 26;
    else
        return x - '0' + 52;
}
void insert(string str) { //插入字符串
    int p = 0, len = str.size();
    for (int i = 0; i < len; i++) {
        int c = getnum(str[i]);
        if (!trie[p][c])
            trie[p][c] = ++idx;
        p = trie[p][c];
        cnt[p]++;
    }
}
int find(string str) { //查询操作
    int p = 0, len = str.size();
    for (int i = 0; i < len; i++) {
        int c = getnum(str[i]);
        if (!trie[p][c])
            return 0;
        p = trie[p][c];
    }
    return cnt[p];
}
//01字典树
const int MAXN = 3200000, MAXBIT = 31;
ll trie[MAXN][2], cnt;
ll num[MAXN];
void init() { //初始化
    memset(trie, 0, sizeof(trie));
    memset(num, 0, sizeof(num));
    cnt = 1;
}
void insert(int n) {
    int cur = 1;
    for (int i = MAXBIT; i >= 0; --i) {
        ll bit = n >> i & 1; // 求出当前位并插入
        if (!trie[cur][bit])
            trie[cur][bit] = ++cnt;
        cur = trie[cur][bit];
    }
    num[cur] = n;
}
ll find_max(int x) { // 找到与x异或最大的那个数
    ll cur = 1;
    for (int i = MAXBIT; i >= 0; --i) {
        ll bit = x >> i & 1;
        if (trie[cur][bit ^ 1]) // 优先走与当前位不同的路径
            cur = trie[cur][bit ^ 1];
        else
            cur = trie[cur][bit];
    }
    return x ^ num[cur];
}