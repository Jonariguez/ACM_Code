/****************
*PID:la3983
*Auth:Jonariguez
*****************
dp+单调队列
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
int dp[maxn],dist[maxn],distOri[maxn],x[maxn],y[maxn],wei[maxn],W[maxn],que[maxn];
int n,C;

int func(int i){
    return dp[i]-dist[i+1]+distOri[i+1];
}


int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&C,&n);
        dist[0]=distOri[0]=0;
        x[0]=y[0]=0;
        W[0]=0;
        for(i=1;i<=n;i++){
            scanf("%d%d%d",&x[i],&y[i],&wei[i]);
            dist[i]=dist[i-1]+abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
            distOri[i]=abs(x[i])+abs(y[i]);
            W[i]=W[i-1]+wei[i];
        }
        int head=1,tail=1;
        for(i=1;i<=n;i++){
            while(head<=tail && W[i]-W[que[head]]>C) head++;
            dp[i]=func(que[head])+dist[i]+distOri[i];
            int FUN=func(i);
            while(head<=tail && func(que[tail])>=FUN) tail--;
            que[++tail]=i;
        }
        printf("%d\n",dp[n]);
        if(T) puts("");
    }
    return 0;
}



