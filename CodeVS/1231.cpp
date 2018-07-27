/****************
*PID:cdvs1231
*Auth:Jonariguez
*****************
最小生成树
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+5;
struct edge{
    int a,b,w;
}s[maxn];

int cmp(const edge &x,const edge &y){
    return x.w<y.w;
}

int par[maxn];

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

bool Union(int a,int b){
    if((a=find(a))==(b=find(b))) return false;
    par[a]=b;
    return true;
}

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=0;i<m;++i)
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].w);
        sort(s,s+m,cmp);
        LL res=0;
        for(i=0;i<=n;i++) par[i]=i;
        int cnt=0;
        for(i=0;i<m;i++){
            if(Union(s[i].a,s[i].b))
                res+=s[i].w,cnt++;
            if(cnt==n-1) break;
        }
        printf("%lld\n",res);
    }
    return 0;
}
