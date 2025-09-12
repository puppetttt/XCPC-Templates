#include <bits/stdc++.h>
using namespace std;
using LL = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void qsort(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = a[rng() % (r - l + 1) + l];
    int i = l, j = r;
    while (i <= j) {
        while (a[i] < mid) {
            ++i;
        }
        while (a[j] > mid) {
            --j;
        }
        if (i <= j) {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    }
    qsort(a, l, j);
    qsort(a, i, r);
}