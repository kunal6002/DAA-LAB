/* time complexity-O(n.w)*/

#include <stdio.h>

int knapsack(int W,int val[],int w[],int n)
{
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else
            {
                int pick=0;
                if(w[i-1]<=j){
                   pick=val[i-1]+dp[i-1][j-w[i-1]];
                }
              int notpick=dp[i-1][j];
              dp[i][j]=(pick>notpick)?pick:notpick;
            }
        }
    }
return dp[n][W];
}

int main()
{
    int n,W;

    printf("Enter number of items: ");
    scanf("%d",&n);

    int val[n],w[n];

    printf("Enter values: ");
    for(int i=0;i<n;i++)
        scanf("%d",&val[i]);

    printf("Enter weights: ");
    for(int i=0;i<n;i++)
        scanf("%d",&w[i]);

    printf("Enter capacity: ");
    scanf("%d",&W);

    printf("Maximum value = %d",knapsack(W,val,w,n));

    return 0;
}
