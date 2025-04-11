#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> ans;
    // std::unordered_map<int, int> mp;
    std::map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        if (!mp.count(x))
        {
            mp[x] = 1;
            ans.push_back(x);
        }
    }
    for (int i = 0; i < ans.size(); i++)
        std::cout << ans[i] << " ";
    std::cout << '\n';
    return;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}