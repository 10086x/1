#include <bits/stdc++.h>

void solve()
{
    std::string s;
    std::cin >> s;
    std::reverse(s.begin(), s.end());
    std::cout << s << '\n';
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