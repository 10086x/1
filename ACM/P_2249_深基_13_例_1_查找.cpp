#include <bits/stdc++.h>

void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        int x;
        std::cin >> x;
        int pos = std::lower_bound(a.begin(), a.end(), x) - a.begin();
        if (x != a[pos])
            std::cout << -1 << " ";
        else
            std::cout << pos + 1 << " ";
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