/****************
*PID:poj3522
*Auth:Jonariguez
*****************
对边排序，然后枚举最小边，一直往后加边，直到图联通
为止，也就是能形成树了。
图联通用并查集维护。
同hdu5624
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100+10;
const int maxm=10000+5;

struct Edge{
    int a,b;
    LL w;
}s[maxm];

int cmp(const Edge &x,const Edge &y){
    return x.w<y.w;
}

struct UFSet{
    int par[maxn];
    void Init(int n){
        for(int i=1;i<=n;i++) par[i]=i;
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    bool Union(int u,int v){
        if((u=find(u))==(v=find(v))) return false;
        par[u]=v;
        return true;
    }
}ufset;

int main()
{
    int i,j,n,m,T;
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        for(i=1;i<=m;i++)
            scanf("%d%d%I64d",&s[i].a,&s[i].b,&s[i].w);
        sort(s+1,s+m+1,cmp);
        LL res=1e18;
        int cnt;
        for(i=1;i<=m;i++){
            cnt=0;
            ufset.Init(n);
            for(j=i;j<=m;j++){
                if(s[j].w-s[i].w>res) break;
                if(ufset.Union(s[j].a,s[j].b)){
                    if(++cnt==n-1) break;
                }
            }
            if(cnt==n-1)
                res=min(res,s[j].w-s[i].w);
        }
        if(res==1e18)
            res=-1;
        printf("%I64d\n",res);
    }
    return 0;
}
