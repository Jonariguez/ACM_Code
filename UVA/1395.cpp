/****************
*PID:uva1395
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
const int INF=10000+10;
int par[maxn],n,m,res;

struct pp{
    int a,b,v;
    bool operator < (const pp &r) const {
        return v<r.v;
    }
}s[maxn*maxn];

void Init(){
    int i;
    for(i=0;i<=n;i++)
        par[i]=i;
}

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

bool Union(int u,int v){
    if((u=find(u))==(v=find(v))) return false;
    par[u]=v;
    return true;
}

void Kruskal(int L){
    int i,j,cnt=0,b=s[L].v;
    Init();
    for(i=L;i<m;i++){
        if(Union(s[i].a,s[i].b)){
            if(++cnt==n-1){
                res=min(res,s[i].v-s[L].v);
                return ;
            }
        }
    }
}


int main()
{
    int i;
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        for(i=0;i<m;i++)
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].v);
        if(m<n-1){
            printf("-1\n");
            continue;
        }
        sort(s,s+m);
     //   for(i=0;i<m;i++)
     //       printf("%d\n",s[i].v);
        res=INF;
        for(i=0;i<=m-n+1;i++)
            Kruskal(i);
        if(res==INF)
            printf("-1\n");
        else
            printf("%d\n",res);
    }
    return 0;
}
