#include <bits/stdc++.h>

void solve()
{
    int n, q;
    std::cin >> n >> q;
    // 下面两种做法都是正确的
    // std::map<std::pair<int, int>, int> mp;
    std::vector<std::map<int, int>> a(n + 1);
    while (q--)
    {
        int op;
        std::cin >> op;
        if (op == 1)
        {
            int i, j, k;
            std::cin >> i >> j >> k;
            // mp[{i, j}] = k;
            a[i][j] = k;
        }
        else if (op == 2)
        {
            int i, j;
            std::cin >> i >> j;
            // std::cout << mp[{i, j}] << '\n';
            std::cout << a[i][j] << '\n';
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