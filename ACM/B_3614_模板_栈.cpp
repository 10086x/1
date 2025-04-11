#include <bits/stdc++.h>
using u64 = unsigned long long;

void solve()
{
    int n;
    std::cin >> n;
    // 注意这题的数据范围，要开unsigned long long
    // 不清楚数据每个数据类型的数据范围可以使用limits库
    // std::numeric_limits<T>::max()返回的是T类型所能表示的最大值
    // 例如std::numeric_limits<unsigned long long>::max()返回的是unsigned long long类型所能表示的最大值
    // std::numeric_limits<T>::min()返回的是T类型所能表示的最小值
    // std::cout << std::numeric_limits<unsigned long long>::max() << '\n';
    // std::cout << std::numeric_limits<unsigned long long>::min() << '\n';
    std::stack<u64> a;
    for (int i = 1; i <= n; i++)
    {
        std::string s;
        std::cin >> s;
        if (s == "push")
        {
            unsigned long long x;
            std::cin >> x;
            a.push(x);
        }
        else if (s == "pop")
        {
            if (a.empty())
                std::cout << "Empty" << '\n';
            else
                a.pop();
        }
        else if (s == "query")
        {
            if (a.empty())
                std::cout << "Anguei!" << '\n';
            else
                std::cout << a.top() << '\n';
        }
        else
            std::cout << a.size() << '\n';
    }
    while (!a.empty())
        a.pop();
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