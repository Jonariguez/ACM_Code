/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
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
#define X first
#define Y second
#define PI acos(-1.0)
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

const int maxn=200000+10;
const int MOD=1e9+7;

LL dp[12][12];

void Init(int p){
    LL now=1;
    int i,j;
    memset(dp,0,sizeof(dp));
    for(i=1;i<=10;i++){
        LL sum=0;
        for(j=0;j<10;j++)
            sum+=dp[i-1][j];
        for(j=0;j<10;j++){
            dp[i][j]=sum;
            if(j==p)
                dp[i][j]+=now;
        }
        now*=10;
    }
}

LL f[15];
int CountBit(int n){
    int c=0;
    while(n){
        c++;
        n/=10;
    }
    return c;
}

LL dfs(int n,int cur,int p){
    if(n==0 || n<=0) return 0LL;
    if(cur==1){
        if(n>=p) return 1LL;
        else return 0LL;
    }
    int m=n/f[cur],i,j;
    LL sum=0;
    for(i=0;i<m;i++)
        sum+=dp[cur][i];
    if(m==p)
        sum+=n%f[cur]+1;
    return sum+dfs(n%f[cur],cur-1,p);
}


int main()
{
    int i,j,T;
    f[1]=1;
    for(i=2;i<=10;i++)
        f[i]=f[i-1]*10;
    scanf("%d",&T);
    while(T--){
        int a,b,p;
        scanf("%d%d%d",&a,&b,&p);
        Init(p);
       // printf("b=%lld\n",dfs(b,CountBit(b),p));
        printf("%lld\n",dfs(b,CountBit(b),p)-dfs(a-1,CountBit(a-1),p));
    }
    return 0;
}

