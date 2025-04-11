#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    do
    {
        for (int i = 0; i < n; i++)
            std::cout << std::setw(5) << a[i];
        std::cout << '\n';
    } while (std::next_permutation(a.begin(), a.end()));
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