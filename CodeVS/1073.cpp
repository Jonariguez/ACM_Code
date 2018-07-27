/****************
*PID:cdvs1073
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=5000+10;

int par[maxn];

void Init(int n){
    for(int i=0;i<=n;i++) par[i]=i;
}

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

void Union(int u,int v){
    if((u=find(u))==(v=find(v))) return ;
    par[u]=v;
}

int main()
{
    int i,j,n,m,p,a,b;
    while(scanf("%d%d%d",&n,&m,&p)!=EOF){
        Init(n);
        for(i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            Union(a,b);
        }
        while(p--){
            scanf("%d%d",&a,&b);
            if(find(a)==find(b))
                puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
