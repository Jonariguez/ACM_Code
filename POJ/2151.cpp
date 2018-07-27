/****************
*PID:poj2151
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxT=1000+10;
const int maxn=30+4;
const int maxm=30+4;
double dp[maxT][maxm][maxn];  //dp[k][i][j]:对于确定的第k个队，前i个题，做出j个题的概率
double P[maxT][maxm],sum[maxT][maxm];
double D[maxT][maxm];   //D[i][j]:前i个队，每个队至少做出1个题，最高做出j个题的概率

int main()
{
    int i,j,k,n,m,T;
    while(scanf("%d%d%d",&m,&T,&n)!=EOF){
        if(m==0 && T==0 && n==0) break;
        for(i=1;i<=T;i++)
            for(j=1;j<=m;j++)
                scanf("%lf",&P[i][j]);
        for(k=1;k<=T;k++){
            dp[k][0][0]=1;
            for(i=1;i<=m;i++){
                for(j=0;j<=i;j++){
                    dp[k][i][j]=dp[k][i-1][j]*(1-P[k][i]); //第i个题没做出来
                    if(j)
                        dp[k][i][j]+=dp[k][i-1][j-1]*P[k][i]; //第i个题做出来了
                }
            }
            sum[k][1]=dp[k][m][1];
            for(i=2;i<=m;i++)
                sum[k][i]=sum[k][i-1]+dp[k][m][i];
        }
        memset(D,0,sizeof(D));
        D[0][1]=1;
        for(i=1;i<=T;i++){
            for(j=1;j<=m;j++){
                //计算D[i][j]时，包括：①D[i-1][1~j-1]*dp[i][m][j] ②D[i-1][j]*dp[i][m][1~j]
                //这样两种情况里的j不能同时取到，因为同时取D[i-1][j]*dp[i][m][j]会算重,
                //在哪里取到j无所谓，只要不同时取得就好，（或者同时取得了再减去，容斥）
              /*  double temp=0;
                for(k=1;k<j;k++) temp+=D[i-1][k];
                D[i][j]=temp*dp[i][m][j];
                D[i][j]+=D[i-1][j]*sum[i][j]; */
                double temp=0;
                for(k=1;k<=j;k++) temp+=D[i-1][k];
                D[i][j]=temp*dp[i][m][j];
                D[i][j]+=D[i-1][j]*sum[i][j-1];
            }
        }
        double res=0;
        for(i=n;i<=m;i++)
            res+=D[T][i];
        printf("%.3f\n",res);
    }
    return 0;
}





