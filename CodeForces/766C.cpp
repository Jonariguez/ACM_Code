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

int dp[1003],f[1003],a[30];
char str[1100];

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        scanf("%s",str+1);
        for(i=0;i<26;i++)
            scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        fill(f,f+n+1,1000000);
        int cnt,sum,now;
        dp[0]=dp[1]=1;f[0]=0;f[1]=1;
        int res=1;
        for(i=2;i<=n;i++){
            cnt=a[str[i]-'a'];
            now=cnt;
            cnt=min(cnt,i);
            for(j=1;j<=cnt;j++){
                if(now<j) break;
                dp[i]=(dp[i]+dp[i-j])%MOD;
                f[i]=min(f[i],f[i-j]+1);
                now=min(now,a[str[i-j]-'a']);
                res=max(res,j);
            }
        }
        printf("%d\n%d\n%d\n",dp[n],res,f[n]);
    }
    return 0;
}

