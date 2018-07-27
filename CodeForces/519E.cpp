/****************
*PID:519e div2
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
int deep[maxn],num[maxn],anc[maxn][20],n,m;
vector<int> son[maxn];

void AddEdge(int u,int v){
    son[u].push_back(v);
    son[v].push_back(u);
}

void init(int u){
    for(int i=1;i<20;i++)
        if(deep[u]>=(1<<i))
            anc[u][i]=anc[anc[u][i-1]][i-1];
}

void dfs(int u){
    init(u);
    int i;
    for(i=0;i<son[u].size();i++){
        int v=son[u][i];
        if(deep[v]) continue;
        anc[v][0]=u;
        deep[v]=deep[u]+1;
        dfs(v);
        num[u]+=num[v];
    }
}

int LCA(int u,int v){
    if(deep[u]<deep[v])
        swap(u,v);
    int i,j;
    for(i=0;deep[u]>=(1<<i);i++);
    i--;
    for(j=i;j>=0;j--)
        if(deep[u]-deep[v]>=(1<<j))
            u=anc[u][j];
    if(u==v) return u;
    for(j=i;j>=0;j--){
        if(anc[u][j]!=-1 && anc[u][j]!=anc[v][j]){
            u=anc[u][j];
            v=anc[v][j];
        }
    }
    return anc[u][0];
}


int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<=n;i++)
            son[i].clear();
        for(i=1;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            AddEdge(a,b);
        }
        for(i=1;i<=n;i++) num[i]=1;
        memset(deep,0,sizeof(deep));
        deep[1]=1;
        dfs(1);
        scanf("%d",&m);
        while(m--){
            int u,v;
            scanf("%d%d",&u,&v);
            if(deep[u]<deep[v]) swap(u,v);
            if((deep[u]-deep[v])%2==1)
                printf("0\n");
            else {
                int w=LCA(u,v),tempu=u,tempv=v;
                int d=(deep[u]+deep[v]-deep[w]*2)/2-1;
                for(int i=0;i<20;i++)
                    if(d&(1<<i)) tempu=anc[tempu][i];
                if(deep[u]==deep[v]){
                    d=deep[v]-deep[w]-1;
                    for(int i=0;i<20;i++)
                        if(d&(1<<i)) tempv=anc[tempv][i];
                    printf("%d\n",n-num[tempu]-num[tempv]);
                }else
                    printf("%d\n",num[anc[tempu][0]]-num[tempu]);
            }
        }
    }
    return 0;
}
