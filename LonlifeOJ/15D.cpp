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

const int maxn=1000+10;
const int MOD=1e9+7;

int n,m,k;
int dp[maxn][maxn];

struct node{
    int S,V;
}s[maxn],a[maxn];

int cmp1(const node &a,const node &b){
    if(b.V==a.V)
        return a.S>b.S;
    return a.V<b.V;
}

bool C(int x){
    if(x>n) return false;
    int i,j;
    for(i=x;i<=n;i++)
        a[i]=s[i];
    memset(dp,0,sizeof(dp));
    for(i=x;i<=n;i++){
        for(j=0;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=s[i].S)
                dp[i][j]=max(dp[i][j],dp[i-1][j-s[i].S]+s[i].V);
        }
    }
    for(i=0;i<=m;i++)
        if(dp[n][i]>=k) return true;
    return false;
}


int main()
{
    int i,j;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++){
        scanf("%d%d",&s[i].S,&s[i].V);
    }
    sort(s+1,s+n+1,cmp1);
    int l=1,r=n,res=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(C(mid)){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    if(res==-1)
        printf("%d\n",res);
    else{
        while(C(res+1)) res++;
        if(res>n) res=n;
        printf("%d\n",s[res].V);
    }
    return 0;
}


