//单调队列
head = 1;
tail = 0;
for (int i = 1; i <= n; ++i) {
    while (head <= tail && q[tail] >= a[i])
        tail--;
    q[++tail] = a[i];
    p[tail] = i;
    while (p[head] <= i - k)
        head++;
    if (i >= k)printf("%d ", q[head]);
}
//单调栈
for (int i = n; i >= 1; i--) {
    while (!s.empty() && a[s.top()] <= a[i]) s.pop();
    f[i] = s.empty() ? 0 : s.top();
    s.push(i);
}