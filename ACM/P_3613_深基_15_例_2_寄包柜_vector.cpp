#include <cstdio>
#include <vector>

void solve()
{
    int n, q;
    scanf("%d %d", &n, &q);
    std::vector<std::vector<int>> a(n + 1);
    while (q--)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int i, j, k;
            scanf("%d %d %d", &i, &j, &k);
            if (a[i].size() < j)
                a[i].resize(j + 1, 0);
            a[i][j] = k;
        }
        else if (op == 2)
        {
            int i, j;
            scanf("%d %d", &i, &j);
            printf("%d\n", a[i][j]);
        }
    }
    return;
}

int main()
{
    int t = 1;
    while (t--)
        solve();
    return 0;
}
