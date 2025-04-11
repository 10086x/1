#include <bits/stdc++.h>

void solve()
{
    int n, op;
    // 注意题目要求是小根堆，所以这里用greater<int>来定义优先队列
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> op;
        if (op == 1)
        {
            std::cin >> op;
            pq.push(op);
        }
        else if (op == 2)
            std::cout << pq.top() << '\n';
        else if (op == 3)
            pq.pop();
    }
    return;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}