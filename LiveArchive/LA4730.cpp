/****************
*PID:LA4730
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
int par[maxn],miny[maxn],maxy[maxn],rank[maxn];

int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}

void Union(int u,int v){
    if((u=find(u))==(v=find(v))) return ;
    miny[v]=min(miny[v],miny[u]);
    maxy[v]=max(maxy[v],maxy[u]);
    par[u]=v;rank[v]+=rank[u];
}

struct BIT{
    int bit[2000005],N;
    void Init(int n){
        N=n;
        memset(bit,0,sizeof(int)*(N+5));
    }
    void add(int x,int y,int v){
        while(x>=1){
            bit[x]-=v;
            x-=x&(-x);
        }
        while(y>=1){
            bit[y]+=v;
            y-=y&(-y);
        }
    }
    int sum(int x){
        int res=0;
        while(x<=N){
            res+=bit[x];
            x+=x&(-x);
        }
        return res;
    }
}state,city;

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int x,y,maxv=-1;
        for(i=0;i<n;i++){
            par[i]=i;rank[i]=1;
            scanf("%d%d",&x,&y);
            y*=2;
            miny[i]=y;maxy[i]=y;
            maxv=max(maxv,y);
        }
        state.Init(maxv);
        city.Init(maxv);
        scanf("%d",&m);
        char str[10];
        int a,b;
        for(i=0;i<m;i++){
            scanf("%s",str);
            if(str[0]=='r'){
                scanf("%d%d",&a,&b);
                x=find(a);y=find(b);
                if(x==y) continue;
                state.add(miny[x]-1,maxy[x],-1);
                city.add(miny[x]-1,maxy[x],-rank[x]);

                state.add(miny[y]-1,maxy[y],-1);
                city.add(miny[y]-1,maxy[y],-rank[y]);

                Union(a,b);
                int f=find(a);
                state.add(miny[f]-1,maxy[f],1);
                city.add(miny[f]-1,maxy[f],rank[f]);
            }else {
                int a;
                double b;
                scanf("%lf",&b);
                a=(int)round(b*2);
                printf("%d %d\n",state.sum(a),city.sum(a));
            }
        }
    }
    return 0;
}
