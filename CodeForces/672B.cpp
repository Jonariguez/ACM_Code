/****************
*PID:672b div2
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

const int maxn=100000+10;
char str[maxn];
int vis[33];

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        scanf("%s",str+1);
        if(n>26){
            puts("-1");
            continue;
        }else {
            memset(vis,0,sizeof(vis));
            int res=0;
            for(i=1;i<=n;i++)
                vis[str[i]-'a']++;
            for(i=0;i<26;i++)
                if(vis[i]) res+=vis[i]-1;
            pfn(res);
        }
    }
    return 0;
}


