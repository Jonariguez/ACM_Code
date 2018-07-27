/****************
*PID:cdvs1069
*Auth:Jonariguez
*****************
用并查集判断是否矛盾，然后排序由大到小贪心处理
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=20000+10;

int par[maxn],rel[maxn],n,m;
struct pp{
    int a,b,c;
}s[100004];

int cmp(const pp &x,const pp &y){
    return x.c>y.c;
}

void Init(int n){
    for(int i=0;i<=n;i++){
        par[i]=i;rel[i]=0;
    }
}

int find(int x){
    if(x==par[x]) return x;
    int y=find(par[x]);
    rel[x]=(rel[x]^rel[par[x]]);
    return par[x]=y;
}

bool Union(int u,int v){
    int pu=find(u),pv=find(v);
    if(pu==pv) return rel[u]==rel[v];//相等的话就是在同一个。
    par[pu]=pv;
    rel[pu]=!(rel[u]^rel[v]);
    return false;
}

int main()
{
    int i,j,n;
    while(scanf("%d%d",&n,&m)!=EOF){
        Init(n);
        for(i=1;i<=m;i++)
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
        sort(s+1,s+m+1,cmp);
        for(i=1;i<=m;i++)
            if(Union(s[i].a,s[i].b)) break;
        printf("%d\n",s[i].c);
    }
    return 0;
}
