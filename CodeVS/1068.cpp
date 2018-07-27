/****************
*PID:cdvs1068
*Auth:Jonariguez
*****************
四维dp，把目前已经用的4中卡片张数看出状态。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=350+10;
const int maxm=120+10;
int dp[45][45][45][45],pos[45][45][45][45],a[maxn],b[5];

int cal(int i,int j,int k,int v){
    return 1+i+j*2+k*3+v*4;
}

int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
        b[x]++;
    }
    pos[0][0][0][0]=1;
    dp[0][0][0][0]=a[1];
    int k,v;
    for(i=0;i<=b[1];i++){
        for(j=0;j<=b[2];j++){
            for(k=0;k<=b[3];k++){
                for(v=0;v<=b[4];v++){
                    if(i)
                        dp[i][j][k][v]=max(dp[i][j][k][v],dp[i-1][j][k][v]+a[cal(i-1,j,k,v)+1]);
                    if(j)
                        dp[i][j][k][v]=max(dp[i][j][k][v],dp[i][j-1][k][v]+a[cal(i,j-1,k,v)+2]);
                    if(k)
                        dp[i][j][k][v]=max(dp[i][j][k][v],dp[i][j][k-1][v]+a[cal(i,j,k-1,v)+3]);
                    if(v)
                        dp[i][j][k][v]=max(dp[i][j][k][v],dp[i][j][k][v-1]+a[cal(i,j,k,v-1)+4]);
                }
            }
        }
    }
    printf("%d\n",dp[b[1]][b[2]][b[3]][b[4]]);
    return 0;
}
