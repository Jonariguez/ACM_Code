/****************
*PID:uva1623
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

const int maxn=1000000+10;
int last[maxn],par[maxn],a[maxn],res[maxn];
deque<int> deq;

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}


int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        while((int)deq.size()) deq.pop_back();
        scanf("%d%d",&n,&m);
       // for(i=1;i<=n;i++) par[i]=i;
        for(i=1;i<=m;i++){
            scanf("%d",&a[i]);
            par[i]=i;
            if(a[i]) par[i]=i+1;
        }
        par[m+1]=m+1;
        memset(last,0,sizeof(last));
        memset(res,0,sizeof(res));
        int yes=1;
        for(i=1;i<=m;i++){
            if(a[i]==0) continue;
            if(last[a[i]]==0){
                int x=find(1);
                if(x>=i){
                    yes=0;break;
                }
                res[x]=a[i];
                par[x]=x+1;
            }else {
                int x=find(last[a[i]]);
                if(x>=i){
                    yes=0;break;
                }
                res[x]=a[i];
                par[x]=x+1;
            }
            last[a[i]]=i;
        }
        if(yes==0)
            puts("NO");
        else {
            PY;
            int f=0;
            for(i=1;i<=m;i++){
                if(a[i]==0){
                    if(f) printf(" ");
                    f++;
                    printf("%d",res[i]);
                }
            }
            puts("");
        }
    }
    return 0;
}




