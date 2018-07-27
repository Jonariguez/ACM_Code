/****************
*PID:hdu5593
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=500000+10;

struct pp{
    int x,y,next;
}edge[maxn];

int tot,n,k,A,B,res,ans;
int son[maxn],f[maxn][11],g[maxn][11];

void add(int x,int y){
    edge[++tot].x=x;edge[tot].y=y;edge[tot].next=son[x];son[x]=tot;
}

//f[u][j]仅记录以u为根且离u的距离是j的个数
void dfs(int u){
    f[u][0]=1;
    int i,j;
    for(i=1;i<=k;i++) f[u][i]=0;
    for(i=son[u];i;i=edge[i].next){
        int v=edge[i].y;
        dfs(v);
        for(j=0;j<k;j++)
            f[u][j+1]+=f[v][j];
    }
}

//g[u][i]记录的是不在以u为根的子树中离u的距离为i的个数
//所以每个节点的解应该有f和g组成
int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&k,&A,&B);
        tot=0;
        for(i=1;i<=n;i++) son[i]=0;
        for(i=2;i<=n;i++)
            add((1LL*A*i%(i-1)+B)%(i-1)+1,i);
        dfs(1);
        res=0;
        for(int x=1;x<=n;x++){
            for(i=son[x];i;i=edge[i].next){
                int v=edge[i].y;
                for(j=0;j<=k;j++) g[v][j]=0;
                g[v][1]=f[x][0];
                for(j=1;j<k;j++)
                    g[v][j+1]+=(f[x][j]-f[v][j-1])+g[x][j];
            }
            ans=0;
            for(i=0;i<=k;i++) ans+=g[x][i]+f[x][i];
            res^=ans;
        }
        printf("%d\n",res);
    }
    return 0;
}
