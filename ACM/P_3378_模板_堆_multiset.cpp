#include <bits/stdc++.h>

void solve()
{
    int n, op;
    std::multiset<int> s;
    std::cin >> n;
    while (n--)
    {
        std::cin >> op;
        if (op == 1)
        {
            int x;
            std::cin >> x;
            s.insert(x);
        }
        else if (op == 2)
        {
            std::cout << *s.begin() << std::endl;
        }
        else if (op == 3)
        {
            s.erase(s.begin());
        }
    }
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