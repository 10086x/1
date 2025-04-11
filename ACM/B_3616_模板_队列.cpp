#include <bits/stdc++.h>

void solve()
{
    int n, op;
    std::queue<int> q;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> op;
        if (op == 1)
        {
            std::cin >> op;
            q.push(op);
        }
        else if (op == 2)
        {
            if (q.empty())
                std::cout << "ERR_CANNOT_POP" << '\n';
            else
                q.pop();
        }
        else if (op == 3)
        {
            if (q.empty())
                std::cout << "ERR_CANNOT_QUERY" << '\n';
            else
                std::cout << q.front() << '\n';
        }
        else if (op == 4)
        {
            std::cout << q.size() << '\n';
        }
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