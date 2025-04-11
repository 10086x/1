#include <bits/stdc++.h>

void solve()
{
    int q;
    std::cin >> q;
    std::vector dq(1000005, std::list<int>());
    for (int i = 1; i <= q; i++)
    {
        std::string op;
        std::cin >> op;
        int a, x;
        std::cin >> a;
        if (op == "push_back")
        {
            std::cin >> x;
            dq[a].push_back(x);
        }
        else if (op == "pop_back")
        {
            if (!dq[a].empty())
                dq[a].pop_back();
        }
        else if (op == "push_front")
        {
            std::cin >> x;
            dq[a].push_front(x);
        }
        else if (op == "pop_front")
        {
            if (!dq[a].empty())
                dq[a].pop_front();
        }
        else if (op == "size")
        {
            std::cout << dq[a].size() << '\n';
        }
        else if (op == "front")
        {
            if (!dq[a].empty())
                std::cout << dq[a].front() << '\n';
        }
        else if (op == "back")
        {
            if (!dq[a].empty())
                std::cout << dq[a].back() << '\n';
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