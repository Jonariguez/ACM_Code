/****************
*PID:671a div1
*Auth:Jonariguez
*****************
dp[i][j]:前i个bottle处理完，只要j参加清理的最小距离。(j=0,只有A；j=1，只有B；j=2，两个都有)
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

const int maxn=100000+10;
const double INF=100000000000000000;
double sum[maxn],Ax,Ay,Bx,By,Tx,Ty,x[maxn],y[maxn],D[maxn];
int vis[maxn];

double dis(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

struct pp{
    double d;
    int a,id;
}s[maxn*2];

int cmp(const pp &x,const pp &y){
    return x.d>y.d;
}

double dp[maxn][3];

int main()
{
    int i,j,n;
    while(scanf("%lf%lf%lf%lf%lf%lf",&Ax,&Ay,&Bx,&By,&Tx,&Ty)!=EOF){
        sc(n);
        memset(vis,0,sizeof(vis));
        for(i=0;i<=n;i++)
            dp[i][0]=dp[i][1]=dp[i][2]=INF;
        sum[0]=0;
        for(i=1;i<=n;i++){
            scanf("%lf%lf",&x[i],&y[i]);
            D[i]=dis(x[i],y[i],Tx,Ty);
            sum[i]=sum[i-1]+D[i];
        }
        dp[0][0]=0;
        for(i=1;i<=n;i++){
            dp[i][0]=min(dp[i][0],dis(x[i],y[i],Ax,Ay)+D[i]+sum[i-1]*2);
            if(i>1)
                dp[i][0]=min(dp[i][0],dp[i-1][0]+D[i]*2);
            dp[i][1]=min(dp[i][1],dis(x[i],y[i],Bx,By)+D[i]+sum[i-1]*2);
            if(i>1)
                dp[i][1]=min(dp[i][1],dp[i-1][1]+D[i]*2);
            if(i>=2){
                dp[i][2]=min(dp[i][2],dp[i-1][2]+D[i]*2);
                dp[i][2]=min(dp[i][2],dp[i-1][0]+dis(x[i],y[i],Bx,By)+D[i]);
                dp[i][2]=min(dp[i][2],dp[i-1][1]+dis(x[i],y[i],Ax,Ay)+D[i]);
            }
        }
      //  printf("%.7f\n%.7f\n%.7f\n",dp[n][0],dp[n][1],dp[n][2]);
        printf("%.10f\n",min(dp[n][0],min(dp[n][1],dp[n][2])));
    }
    return 0;
}

/*
0 1 1 0 1 1
1
2 1
*/


