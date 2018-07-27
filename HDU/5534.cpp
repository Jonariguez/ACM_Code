/****************
*PID:hdu5534
*Auth:Jonariguez
*****************
树的节点的度总和为2n-2，每个度有一个value，做完全背包
因为是树，联通，可以先每个点都是1度，res=f[1]*n，然后
再为n个点分配n-2个度，注意，这时再分配一个度就是2度了，
那么得到的value是f[2],故要处理f[i]=f[i+1]。因为多一个
多度(即度大于1的点，就少一个1度的点，故还要把每个value
都-f[1],即处理f[i]-=temp(temp=f[1])
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

const int maxn=2015+10;
const int INF=1e9;
int dp[2][maxn],f[maxn];

int main()
{
    int i,j,n,T;
    sc(T);
    while(T--){
        sc(n);
        for(i=1;i<n;i++)
            sc(f[i]);
        int res=f[1]*n,temp=f[1];
        for(i=1;i<n;i++) f[i]-=temp;
        for(i=0;i<=0;i++)
            for(j=0;j<=n;j++) dp[i][j]=-INF;
        int *pre=dp[0],*now=dp[1];
        pre[0]=0;
        for(i=1;i<n-1;i++)
            f[i]=f[i+1];
        for(i=1;i<n-1;i++){
            for(j=1;j<=n-2;j++){
                if(j<i) now[j]=pre[j];
                else now[j]=max(pre[j],now[j-i]+f[i]);
            }
            swap(now,pre);
        }
        res+=pre[n-2];
        pfn(res);
    }
    return 0;
}


