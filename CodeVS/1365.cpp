/****************
*PID:cdvs1365
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=20000+10;
int par[maxn];

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

void Union(int u,int v){
    if((u=find(u))==(v=find(v))) return ;
    par[u]=v;
}

int main()
{
    int i,j,x,n,m;
    while(scanf("%d%d%d",&x,&n,&m)!=EOF){
        for(i=0;i<=x;i++) par[i]=i;
        int a,b;
        for(i=1;i<=n;i++){
            scanf("%d%d",&a,&b);
            Union(a,b);
        }
        while(m--){
            scanf("%d%d",&a,&b);
            a=find(a);b=find(b);
            if(a==b) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
