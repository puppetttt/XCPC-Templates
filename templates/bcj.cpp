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
void Union(int Root1, int Root2) {
    if (Root1 == Root2) return;
    int height1 = abs(Root1);
    int height2 = abs(Root2);
    if (height1 > height2) {
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    } else {
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
}
void Union(int Root1, int Root2) {
    if (Root1 == Root2) return;
    S[Root1] = Root2;
}