/****************
*PID:SGU495
*Auth:Jonariguez
*****************
因为每个人如果拿到了礼物，那么就是拿到1个礼物。
由期望的线性性可得，拿到礼物个数的期望就是每个
拿到礼物的概率之和。
dp[i]:第i个人拿到礼物的概率
分析第i个人拿到礼物的概率：如果第i-1个人没有拿到
礼物，则第i个拿到礼物的概率和第i-1个人拿到礼物的
概率是一样的，即P(和第i-1个人一样)*P(第i个人没拿到);
如果第i-1个人拿到了，则第i个拿到礼物的概率会比
第i-1个人拿到礼物的概率小1/n，即
P(第i-1个人拿到的概率)*(P(第i-1个人拿到的概率-)-1/n)
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
double dp[maxn]; //dp[i]:第i个拿到礼物的概率

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        for(i=2;i<=m;i++)
            dp[i]=(1-dp[i-1])*dp[i-1]+dp[i-1]*(dp[i-1]-1.0/n);
        double res=0;
        for(i=1;i<=m;i++)
            res+=dp[i];
        printf("%.10f\n",res);
    }
    return 0;
}



