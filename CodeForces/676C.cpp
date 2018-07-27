/****************
*PID:676c div2
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
    int i,j,n,m,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        scanf("%s",str+1);
        memset(vis,0,sizeof(vis));
        int res=0,res2=0,s,t,a=0,b=0;
        s=1;t=1;
        while(t<=n){//puts("??");
            while(t<=n){
                int temp=str[t]-'a';
                if(vis[temp]+1>k && vis[temp^1]>k) break;
                vis[temp]++;
                t++;
            }
          //  printf("t=%d s=%d\n",t,s);
            if(t>n){
                res=max(res,t-s);break;
            }
            res=max(res,t-s);
            vis[str[s]-'a']--;
            s++;
        }
        pfn(res);
    }
    return 0;
}



