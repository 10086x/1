#include <bits/stdc++.h>
using i64 = long long;

// 本题是知名问题(指Leetcode No.1)两数之和的一个变种，在两数之和中，我们需要求出给定的n个整数中有多少对整数的和等于给定的值
// 即我们需要求出所有的i,j使得a[i]+a[j]=c，其中i!=j
// 使用哈希表(std::unordered_map)可以在O(n)的时间复杂度内解决这个问题
// 使用map可以在O(nlogn)的时间复杂度内解决这个问题
// 大体思路是，我们遍历数组，对于每一个a[i]，我们判断c-a[i]是否在哈希表中，如果在的话，那么就说明有若干对a[i]和c-a[i]的和等于c
// 而在本题中，我们需要求出给定的n个整数中有多少对整数的差等于给定的值。
// 即我们需要求出所有的i,j使得a[i]-a[j]=c，其中i!=j
// 稍微变换一下，我们可以得到a[i]-c=a[j]，我们判断a[i]-c是否在哈希表中，如果在的话，那么就说明有若干a[i]和a[i]-c的差等于c

void solve()
{
    int n, c;
    std::cin >> n >> c;
    std::vector<int> a(n);
    // std::map<int, int> mp;
    std::unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        mp[a[i]]++;
    }
    // 经过判断，ans的值可能会超过int的范围，所以我们使用long long来存储ans
    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp.count(a[i] - c))
            ans += mp[a[i] - c];
    }
    std::cout << ans << '\n';
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