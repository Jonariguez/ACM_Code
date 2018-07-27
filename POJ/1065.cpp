/****************
*PID:poj1065
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

const int maxn=5000+10;
int vis[maxn];
struct Stick{
    int L,W;
}s[maxn];

int cmp(const Stick &x,const Stick &y){
    if(x.L==y.L)
        return x.W<y.W;
    return x.L<y.L;
}

int main()
{
    int i,j,n,m,T;
    sc(T);
    while(T--){
        sc(n);
        for(i=1;i<=n;i++){
            scanf("%d%d",&s[i].L,&s[i].W);
        }
        sort(s+1,s+n+1,cmp);
        memset(vis,0,sizeof(vis));
        int cnt=0,res=0;
        while(cnt<n){
            i=1;
            while(i<=n && vis[i]) i++;
            if(i>n) break;
            res++;
            for(j=i;j<=n;j++){
                if(vis[j]==0 && s[j].L>=s[i].L && s[j].W>=s[i].W){
                    vis[j]=1;cnt++;i=j;
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}


