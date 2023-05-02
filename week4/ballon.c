#include <stdio.h>
#include <limits.h>

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }

    return b;
}

int getMaxCoin(int *arr, int size)
{
    int n = size+2;

    int p[n];
    p[0] = 1;
    p[n-1] = 1;

    for (int i = 1; i < n-1; i++)
    {
        p[i] = arr[i - 1];
    }

    // int c = size + 2;
    // int n = c - 1;

    int DP[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            DP[i][j] = 0;
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            int x = j + i - 1;
            // DP[i][j] = INT_MIN;

            for (int k = j; k <= x; k++)
            {
                DP[j][x] = max(DP[j][x], DP[j][k - 1] + p[j - 1] * p[k] * p[x + 1] + DP[k + 1][x]);
            }
        }
    }

    return DP[1][n - 2];
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int ans = getMaxCoin(arr, n);

    printf("%d\n", ans);

    return 0;
}