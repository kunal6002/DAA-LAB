#include <stdio.h>
#include <limits.h>

int matrixChain(int p[], int n)
{
    int dp[n][n];

    // Cost is 0 when there is only one matrix
    for(int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }

    // Length of matrix chain
    for(int len = 2; len < n; len++)
    {
        for(int i = 1; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            // Try every possible split
            for(int k = i; k < j; k++)
            {
                int cost = dp[i][k]
                         + dp[k+1][j]
                         + p[i-1] * p[k] * p[j];

                if(cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n-1];
}

int main()
{
    int n;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];

    printf("Enter dimensions:\n");
    printf("For A1 = p0 x p1, A2 = p1 x p2, ...\n");

    for(int i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Minimum number of multiplications = %d",
           matrixChain(p, n + 1));

    return 0;
}