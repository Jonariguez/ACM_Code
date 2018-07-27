/****************
*PID:650c div1
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000000+5;
int a[maxn],par[maxn],deg[maxn],n,m;
map<int,int> mp[maxn];
vector<int> G[maxn];

void Init(int n){
    for(int i=0;i<=n;i++){
        par[i]=i;deg[i]=0;
    }
}

void add(int u,int v){
    G[u].push_back(v);
    deg[v]++;
}

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

void Union(int u,int v){
    u=find(u);v=find(v);
    if(u!=v) par[u]=v;
}

int ID(int i,int j){    //编号，将二维变成一维。
    return (i-1)*m+j;
}

int ci,cj;

int cmpi(int x,int y){
    return a[ID(ci,x)]<a[ID(ci,y)];
}

int cmpj(int x,int y){
    return a[ID(x,cj)]<a[ID(y,cj)];
}

int ord[maxn];
vector<int> order;
int ans[maxn];

void topo(){
    int i;
    queue<int> que;
    for(i=1;i<=n*m;i++){
        if(find(i)==i && deg[i]==0) que.push(i);    //只处理父亲，然后输出的时候，每个点的值就是它父亲的值。
        ans[i]=1;
    }
    order.clear();
    while(!que.empty()){
        int u=que.front();que.pop();
        order.push_back(u);
        for(i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(--deg[v]==0)
                que.push(v);
        }
    }
  //  memset(ans,0,sizeof(ans);
    for(i=0;i<order.size();i++){    //从起点(最小值)开始标值。
        int u=order[i];
        for(int j=0;j<G[u].size();j++){
            int v=G[u][j];
            ans[v]=max(ans[v],ans[u]+1);  //从行标和从列标的值可能不同，取较大值才符合。
        }
    }
}

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                int p=ID(i,j);
                scanf("%d",&a[p]);
                par[p]=p;deg[p]=0;
                G[p].clear();
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++) ord[j]=j; //odr[j]:第j小的在ord[j]位置。
            ci=i;
            sort(ord+1,ord+m+1,cmpi);
            for(j=1;j<m;j++){               //按行缩点
                if(a[ID(i,ord[j])]==a[ID(i,ord[j+1])]){
                    Union(ID(i,ord[j]),ID(i,ord[j+1]));
                }
            }
        }
        for(j=1;j<=m;j++){
            for(i=1;i<=n;i++) ord[i]=i;
            cj=j;
            sort(ord+1,ord+n+1,cmpj);
            for(i=1;i<n;i++){               //按列缩点
                if(a[ID(ord[i],j)]==a[ID(ord[i+1],j)]){
                    Union(ID(ord[i],j),ID(ord[i+1],j));
                }
            }
        }

        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++) ord[j]=j;
            ci=i;
            sort(ord+1,ord+m+1,cmpi);
            for(j=1;j<m;j++){               //根据大小关系连边，确定拓扑关系。
                if(a[ID(i,ord[j])]<a[ID(i,ord[j+1])]){
                    add(find(ID(i,ord[j])),find(ID(i,ord[j+1])));
                }
            }
        }
        for(j=1;j<=m;j++){
            for(i=1;i<=n;i++) ord[i]=i;
            cj=j;
            sort(ord+1,ord+n+1,cmpj);
            for(i=1;i<n;i++){
                if(a[ID(ord[i],j)]<a[ID(ord[i+1],j)]){
                    add(find(ID(ord[i],j)),find(ID(ord[i+1],j)));
                }
            }
        }
        topo();     //拓扑排序。

        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++)
                printf("%d ",ans[find(ID(i,j))]);
            puts("");
        }
    }
    return 0;
}
