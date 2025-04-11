#include <bits/stdc++.h>

void solve()
{
    int n, q;
    std::cin >> n >> q;
    std::vector<std::vector<int>> a(n + 1);
    while (q--)
    {
        int op;
        std::cin >> op;
        if (op == 1)
        {
            int i, j, k;
            std::cin >> i >> j >> k;
            if (a[i].size() < j)
                a[i].resize(j + 1, 0);
            a[i][j] = k;
        }
        else if (op == 2)
        {
            int i, j;
            std::cin >> i >> j;
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