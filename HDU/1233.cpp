/****************
*PID:hdu1233
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=100+5;
const int maxm=1000+5;
int par[maxn],n,m,tot;

struct pp{
    int a,b,w;
}s[maxn*maxn];

int cmp(const pp &x,const pp &y){
    return x.w<y.w;
}

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

bool merge(int u,int v){
    if((u=find(u))==(v=find(v))) return false;
    par[u]=v;
    return true;
}

int main()
{
    int i,j,T;
    while(scanf("%d",&n),n){
        for(i=1;i<=n;i++){
            par[i]=i;
        }
        m=(n-1)*n/2;
        for(i=0;i<m;i++){
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].w);
        }
        sort(s,s+m,cmp);
        int res=0,cnt=0;
        for(i=0;i<m;i++){
            if(merge(s[i].a,s[i].b)){
                res+=s[i].w;
                if(++cnt==n-1) break;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
