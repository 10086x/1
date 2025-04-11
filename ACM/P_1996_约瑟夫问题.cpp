#include <bits/stdc++.h>

// 约瑟夫问题由来已久，而这个问题的解法也在不断改进
// 只是目前仍没有一个极其高效的算法（log以内）解决这个问题。
// 我们的思路是使用一个双端队列来模拟这个过程，时间复杂度为O(n^2)

// 设 J_{n,k} 表示规模分别为 n,k 的约瑟夫问题的答案。我们有如下递归式
// J_{n,k} = (J_{n-1,k} + k) % n
// 这个也很好推。你从 0 开始数 k 个，让第 k-1 个人出局后剩下 n-1 个人
// 你计算出在 n-1 个人中选的答案后，再加一个相对位移 k 得到真正的答案。这个算法的复杂度显然是O(n)的。

void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::deque<int> dq;
    for (int i = 1; i <= n; i++)
        dq.push_back(i);
    int cnt = 0;
    while (!dq.empty())
    {
        cnt++;
        if (cnt % m == 0)
        {
            std::cout << dq.front() << " ";
            dq.pop_front();
        }
        else
        {
            dq.push_back(dq.front());
            dq.pop_front();
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