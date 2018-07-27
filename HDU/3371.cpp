/****************
*PID:hdu3371
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

const int maxn=500+10;
const int maxm=25000+10;
int par[maxn],mp[maxn][maxn];

struct pp{
    int a,b,w;
}t[maxm],s[maxm];

void Init(int n){
    for(int i=0;i<=n;i++)
        par[i]=i;
}

int cmp(const pp &x,const pp &y){
    return x.w<y.w;
}

int Find(int x){
    return x==par[x]?x:par[x]=Find(par[x]);
}

bool Union(int u,int v){
    if((u=Find(u))==(v=Find(v))) return false;
    par[u]=v;
    return true;
}

int main()
{
    int i,j,n,m,k,T,kcase=0;
    scanf("%d",&T);
    while(T--){
        kcase++;
        scanf("%d%d%d",&n,&m,&k);
        for(i=1;i<=m;i++)
            scanf("%d%d%d",&t[i].a,&t[i].b,&t[i].w);
      //  sort(s+1,s+m+1,cmp);
        Init(n);
        int cnt=n;
        while(k--){
            int t,a,b;
            sc(t);
            t--;
            scanf("%d",&a);
            while(t--){
                sc(b);
                mp[a][b]=mp[b][a]=kcase;
                if(Union(a,b))
                    cnt--;
            }
        }
        int tot=0;
        for(i=1;i<=m;i++){
            if(mp[t[i].a][t[i].b]==kcase) continue;
            s[tot++]=t[i];
        }
        sort(s,s+tot,cmp);
        int res=0;
        for(i=0;i<tot && cnt>1;i++){
            if(Union(s[i].a,s[i].b)){
                res+=s[i].w;
                if(--cnt==1)
                    break;
            }
        }
        if(cnt>1)
            puts("-1");
        else
            pfn(res);
    }
    return 0;
}





