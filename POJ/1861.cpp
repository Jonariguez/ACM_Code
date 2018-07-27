/*
最小生成树
*/
#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1001+10;
const int maxm=15000+10;

struct dege{
    int x,y;
}e[maxn];

struct pp{
    int f,t,v;
}s[maxm];

int cmp(const pp &x,const pp &y){
    return x.v<y.v;
}

typedef struct UFSet{
    int par[maxn];        //按秩合并应该会好一点
    void init(int n){for(int i=0;i<=n;i++) par[i]=i;}
    int Find(int x){ return par[x]==x?x:par[x]=Find(par[x]);}
    bool Union(int u,int v){
        if((u=Find(u))==(v=Find(v))) return false;
        par[u]=v;
        return true;
    }
}UFSet;

int main()
{
    int n,m,i,j,a,b,c;
    scanf("%d%d",&n,&m);
    UFSet ss;
    ss.init(n);
    for(i=0;i<m;i++)
        scanf("%d%d%d",&s[i].f,&s[i].t,&s[i].v);
    sort(s,s+m,cmp);
    int cnt=0,tot,maxv=-1;
    for(i=0;i<m;i++){
        if(ss.Union(s[i].f,s[i].t)){
            if(maxv<s[i].v) maxv=s[i].v;
            e[cnt].x=s[i].f;e[cnt].y=s[i].t;
            if(++cnt==n-1) break;
        }
    }
    printf("%d\n%d\n",maxv,n-1);        //既然是生成树，边肯定是n-1条啊。。。
    for(i=0;i<cnt;i++)
        printf("%d %d\n",e[i].x,e[i].y);
    return 0;
}
