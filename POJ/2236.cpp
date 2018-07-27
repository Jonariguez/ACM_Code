/*
并查集
*/
#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1001+10;
int vis[maxn];

typedef struct UFSet{
    int par[maxn],ran[maxn];        //按秩合并应该会好一点
    void init(){for(int i=0;i<maxn;i++) par[i]=i,ran[i]=1;}
    int Find(int x){ return par[x]==x?x:par[x]=Find(par[x]);}
    void Union(int u,int v){
        if((u=Find(u))==(v=Find(v))) return ;
        if(ran[u]>ran[v]){
            par[v]=u;ran[u]+=ran[v];
        }
        else {
            par[u]=v;
            if(ran[u]==ran[v]) ran[v]++;
            else ran[v]+=ran[u];
        }
    }
}UFSet;

struct point{
    int x,y;
}p[maxn];

vector<int> v[maxn];

int dis(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main()
{
    int i,j,n,d,a,b;
    char op[4];
    UFSet s;
    s.init();
    memset(vis,0,sizeof(vis));
    scanf("%d%d",&n,&d);
    for(i=1;i<=n;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    for(i=1;i<=n;i++)               //这里可以预处理一下
        for(j=1;j<=n;j++)
            if(i!=j && dis(p[i].x,p[i].y,p[j].x,p[j].y)<=d*d)
                v[i].push_back(j);

    while(scanf("%s",op)!=EOF){     //这里要用EOF
        if(op[0]=='O'){
            scanf("%d",&a);
            vis[a]=1;
            int t=v[a].size();
            for(i=0;i<t;i++)
                if(vis[v[a][i]])
                    s.Union(a,v[a][i]);
        }else if(op[0]=='S'){
            scanf("%d%d",&a,&b);
            if(vis[a]==0 || vis[b]==0)
                printf("FAIL\n");
            else {
                a=s.Find(a);b=s.Find(b);
                if(a!=b)
                    printf("FAIL\n");
                else
                    printf("SUCCESS\n");
            }
        }
    }
    return 0;
}
