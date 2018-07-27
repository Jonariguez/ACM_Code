/****************
*PID:poj1733
*Auth:Jonariguez
*****************
n太大，需要离散
如果a到b是odd，则可以理解成b比a-1多奇数个。
类似于hdu3038
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=5000+10;
int Hash[maxn*2],par[maxn*2],rel[maxn*2],tot,n,m;

struct command{
    int a,b,o;
}s[maxn];

int get(int u){
    return (lower_bound(Hash,Hash+tot,u)-Hash)+1;
}

int find(int x){
    if(par[x]==x) return x;
    int y=find(par[x]);
    rel[x]^=rel[par[x]];
    return par[x]=y;
}

int main()
{
    int i,j,res;
    scanf("%d%d",&n,&m);
    tot=0;
    for(i=0;i<maxn*2;i++){
        par[i]=i;rel[i]=0;
    }
    for(i=1;i<=m;i++){
        char str[11];
        scanf("%d%d%s",&s[i].a,&s[i].b,str);
        if(str[0]=='e') s[i].o=0;
        else s[i].o=1;
        Hash[tot++]=s[i].a;
        Hash[tot++]=s[i].b;
    }
    sort(Hash,Hash+tot);
    tot=unique(Hash,Hash+tot)-Hash;
   // printf("%d\n",tot);
    for(i=1;i<=m;i++){
        int u=get(s[i].a),v=get(s[i].b);
        u--;
       // printf("u=%d v=%d\n",u,v);
        int pu=find(u),pv=find(v);
        if(pu!=pv){
            par[pu]=pv;
            rel[pu]=rel[u]^rel[v];
            if(s[i].o) rel[pu]=!rel[pu];
        }else {
            if(rel[u]^rel[v]!=s[i].o) break;
          //  puts("??");
        }
    }
    printf("%d\n",i-1);
    return 0;
}
