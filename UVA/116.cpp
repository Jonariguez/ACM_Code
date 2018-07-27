/****************
*PID:uva116
*Auth:Jonariguez
*****************
多段图的动态规划。因为要字典序最小，所以倒着来，
设d[i][j]为从(i,j)到最后一列的最小开销，
则d[i][j]=a[i][j]+max(d[i+1][j+1],d[i-1][j+1])
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+5;
const int INF=1000000000;
int dp[maxn][maxn],n,m,a[maxn][maxn],next[maxn][maxn];

int main()
{
    int i,j;
    while(scanf("%d%d",&m,&n)==2 && m){
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        }
        int first=1,res=INF;
        for(j=n;j>=1;j--){  //j列
            for(i=1;i<=m;i++){
                if(j==n) dp[i][j]=a[i][j];
                else {
                    int row[3]={i,i-1,i+1};
                    if(i==1) row[1]=m;
                    if(i==m) row[2]=1;
                    sort(row,row+3);
                    dp[i][j]=INF;
                    for(int k=0;k<3;k++){
                        int v=dp[row[k]][j+1]+a[i][j];
                        if(v<dp[i][j]){
                            dp[i][j]=v;next[i][j]=row[k];   //next[i][j]表示最终答案路径从格子(i,j)到下一列时的行号
                        }
                    }
                }
                if(j==1 && res>dp[i][j]){   //到第一列了，就更新res和first，first即最优解路径开始的第一列的行号
                    res=dp[i][j];first=i;
                }
            }
        }
        printf("%d",first);
        for(i=next[first][1],j=2;j<=n;i=next[i][j],j++)
            printf(" %d",i);
        printf("\n%d\n",res);
    }
    return 0;
}
