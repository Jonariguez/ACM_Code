/****************
*PID:hdu4089
*Auth:Jonariguez
*****************
题意：有n个人排队等着在官网上激活游戏。Tomato排在第m个。
对于队列中的第一个人。有一下情况：
1、激活失败，留在队列中等待下一次激活（概率为p1)
2、失去连接，出队列，然后排在队列的最后（概率为p2）
3、激活成功，离开队列（概率为p3）
4、服务器瘫痪，服务器停止激活，所有人都无法激活了。
求服务器瘫痪时Tomato在队列中的位置<=k的概率

概率DP；
设dp[i][j]表示i个人排队,Tomato排在第j个位置，达到目标状态的概率(j<=i)
dp[n][m]就是所求
j==1:    dp[i][1]=p1*dp[i][1]+p2*dp[i][i]+p4;
2<=j<=k: dp[i][j]=p1*dp[i][j]+p2*dp[i][j-1]+p3*dp[i-1][j-1]+p4;
k<j<=i:  dp[i][j]=p1*dp[i][j]+p2*dp[i][j-1]+p3*dp[i-1][j-1];
化简：
j==1:    dp[i][1]=P2*dp[i][i]+P4;
2<=j<=k: dp[i][j]=P2*dp[i][j-1]+P3*dp[i-1][j-1]+P4;
k<j<=i:  dp[i][j]=P2*dp[i][j-1]+P3*dp[i-1][j-1];

其中：P2=p2/(1-p1),P3=p3/(1-p1),P4=p4/(1-p1)
既然是递推，dp[i-1][j-1]就是已知的常数，dp[i][j]都是由前一项递推过来的，
但是dp[i][1]是由dp[i][i]递推的，所以可以从dp[i][1]迭代到dp[i][i]共i项，
这样就得到类似于dp[i][i]=dp[i][i]*P2^i+C 化简得：dp[i][i]=C/(1-P2^i)
其中C是可以迭代维护得到。然后就可以愉快地往后递推了。
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
#define eps 1e-8
const int maxn=2000+10;
double dp[maxn][maxn],fact[maxn],c[maxn];

int main()
{
    int i,j,n,m,k,T,kcase=1;
    double p1,p2,p3,p4,P1,P2,P3,P4;
    while(scanf("%d%d%d%lf%lf%lf%lf",&n,&m,&k,&p1,&p2,&p3,&p4)!=EOF){
        if(fabs(p4)<=eps){
            printf("0.00000\n");continue;
        }
        P2=p2/(1-p1);
        P3=p3/(1-p1);
        P4=p4/(1-p1);
        fact[0]=1.0;
        for(i=1;i<=n;i++)
            fact[i]=fact[i-1]*P2;
        dp[1][1]=P4/(1-P2);
        for(i=2;i<=n;i++){
            c[1]=P4;
            for(j=2;j<=min(k,i);j++)
                c[j]=c[j-1]*P2+P3*dp[i-1][j-1]+P4;
            for(j=k+1;j<=i;j++)
                c[j]=c[j-1]*P2+P3*dp[i-1][j-1];
            dp[i][i]=c[i]/(1-fact[i]);
            dp[i][1]=P2*dp[i][i]+P4;
            for(j=2;j<=min(i,k);j++)
                dp[i][j]=P2*dp[i][j-1]+P3*dp[i-1][j-1]+P4;
            for(j=k+1;j<i;j++)
                dp[i][j]=P2*dp[i][j-1]+P3*dp[i-1][j-1];
        }
        printf("%.5f\n",dp[n][m]);
    }
    return 0;
}

