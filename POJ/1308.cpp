#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=200000+10;
int vis[maxn];
typedef struct UFSet{
    int par[maxn];
    void Init(){ for(int i=0;i<maxn;i++) par[i]=i;}
    int Find(int x){ return par[x]==x?x:par[x]=Find(par[x]);}
    bool Union(int u,int v){
        if((u=Find(u))==(v=Find(v))) return false;
        par[v]=u;
        return true;
    }
}UFSet;

int main()
{
    int i,a,b,kcase=1,maxv;
    UFSet s;
    while(scanf("%d%d",&a,&b)){
        if(a==-1 && b==-1) break;
        if(a==0 && b==0){
            printf("Case %d is a tree.\n",kcase++);
            continue;
        }
        memset(vis,0,sizeof(vis));
        s.Init();
        s.Union(a,b);
        int flag=1,cnt=2;
        maxv=max(a,b);
        vis[a]=vis[b]=1;
        while(scanf("%d%d",&a,&b)){
            if(a==0 && b==0) break;
            if(vis[a]==0) cnt++;
            if(vis[b]==0) cnt++;
            vis[a]=vis[b]=1;
            maxv=max(maxv,(max(a,b)));
            if(!s.Union(a,b) && flag)
                flag=0;
        }
        if(flag==0)
            printf("Case %d is not a tree.\n",kcase++);
        else {
            int cnt2=0;
            for(i=1;i<=maxv;i++) if(s.par[i]==i) cnt2++;
            if(cnt2!=maxv-cnt+1)
                printf("Case %d is not a tree.\n",kcase++);
            else
                printf("Case %d is a tree.\n",kcase++);
        }
    }
    return 0;
}
