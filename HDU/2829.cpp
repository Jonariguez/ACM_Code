/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(i,n) for(i=0;j<=(n);i++)
#define re(i,n) for(i=1;i<(n);i++)
#define re0(i,n) for(i=0;i<(n);i++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("d",&x,&y)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define PI acos(-1.0)
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
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
typedef long long Ll;
Ll Pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=1000+10;
const int MOD=1e9+7;

LL sum[maxn],sum2[maxn],dp[maxn][maxn];
int a[maxn],st[maxn],head,tail;

LL getUp(int k,int j,int pre){
    return dp[pre][k]+sum[k]*sum[k]-sum2[k]-(dp[pre][j]+sum[j]*sum[j]-sum2[j]);
}

LL getDown(int k,int j){
    return sum[k]-sum[j];
}

bool better2(int k,int j,int pre,LL cmp){
    return getUp(k,j,pre)>cmp*getDown(k,j);
}

bool better3(int k,int j,int i,int pre){
    return getUp(i,j,pre)*getDown(j,k)<getUp(j,k,pre)*getDown(i,j);
}

int ask(LL v,int pre){
    while(head<tail-1 && better2(st[head],st[head+1],pre,v)) head++;
    return st[head];
}

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0 && m==0) break;
        sum[0]=sum2[0]=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
            sum2[i]=sum2[i-1]+sum[i-1]*a[i];
        }
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++) dp[0][i]=sum2[i];
        for(i=1;i<=m;i++){
            head=tail=0;
            st[tail++]=0;
            for(j=1;j<=n;j++){
                int p=ask(sum[j],i-1);
                dp[i][j]=dp[i-1][p]-sum[p]*(sum[j]-sum[p])+sum2[j]-sum2[p];
                while(head<tail-1 && better3(st[tail-2],st[tail-1],j,i-1)) tail--;
                st[tail++]=j;
            }
        }
        printf("%I64d\n",dp[m][n]);
    }
    return 0;
}



