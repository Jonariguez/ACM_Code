/*
Prim+Heap 次小生成树
下面注释的T指的是图G的最小生成树
根据思想，然后自己写的，没想到1A了，一开始还是怀疑自己的实现能力的
以后思路清晰就往上敲，不要看代码
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn=100+10;
const int INF=1e9+9;
int n,m;
int map[maxn][maxn],max_val[maxn][maxn];

struct Edge{
    int a,b,v;
    Edge(int _a=1,int _b=1,int _v=INF):a(_a),b(_b),v(_v){}
    bool operator < (const Edge &e) const {
        return v>e.v;
    }
};

vector<vector<Edge> > G(maxn);
vector<int> save;   //已经添加到MST中的点

void Input(){
    int i,a,b,v;
    scanf("%d%d",&n,&m);
    memset(map,0,sizeof(map));
    for(i=0;i<=n;i++)
        G[i].clear();
    while(m--){
        scanf("%d%d%d",&a,&b,&v);
        map[a][b]=map[b][a]=v;
        G[a].push_back(Edge(a,b,v));
        G[b].push_back(Edge(b,a,v));
    }
}

int HeapPrim(){
    int i,j,k;
    int vis[maxn],dis[maxn];
    for(i=0;i<=n;i++)
        vis[i]=0,dis[i]=INF;
    int TreeLong=0,tot=0;
    priority_queue<Edge> pq;
    save.clear();
    pq.push(Edge(1,1,0));
    save.push_back(1);
    while(tot<n && !pq.empty()){
        Edge E;
        do{
            E=pq.top();pq.pop();
        }while(vis[E.b]==1 && !pq.empty());
        if(vis[E.b]==0){
            TreeLong+=E.v;vis[E.b]=1;tot++;
            int from=E.a,to=E.b,vv=E.v;
            max_val[from][to]=max_val[to][from]=vv;
            save.push_back(to);         //注意！！要先将to点加到T中，因为更新max_val的时候也对它更新，不然后会WA
            for(j=0;j<save.size();j++)
                max_val[j][to]=max_val[to][j]=max(max_val[j][from],max_val[from][to]);  //注意这里max_val[][]也是双向的

            map[from][to]=map[to][from]=0;      //要进行删边，就是在图中把加入最小生成树T的边删掉
            if(tot==n) break;
            for(j=0;j<G[to].size();j++){
                int aa=G[to][j].a,bb=G[to][j].b;
                if(vis[bb]==0){
                    int w=G[to][j].v;
                    if(dis[bb]>w){
                        dis[bb]=w;
                        pq.push(Edge(aa,bb,w));
                    }
                }
            }
        }
    }
    return TreeLong;
}

/*
生成次小生成树：在T中删除一条边，然后再加入一条边形成一个新的树就是次小生成树。
次小权值和可能等于最小的取值和，即最小不唯一。
所以由定义，如果加的那条新边和删除的相等，说明形成的次小生成树就是另外一棵异于T
的最小生成树，此时说明最小生成树不唯一。
具体到程序里上面说的要加入的边是a-b这条边(权值map[a][b])，那么应该删除的边的权值就
是max_val[a][b],所以如果map[a][b]==max_val[a][b]，说明最小生成树不唯一
*/
bool UniqueJudge(){
    int i,j,flag=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            if(map[i][j]==0)
                continue;
            if(map[i][j]==max_val[i][j]){   //如果修改一条边就是
                flag=1;break;
            }
        }
    if(flag)
        return false;
    return true;
}

int main()
{
    int i,j,t,MST;
    scanf("%d",&t);
    while(t--){
        Input();
        MST=HeapPrim();
        if(UniqueJudge())
            printf("%d\n",MST);
        else
            printf("Not Unique!\n");
    }
    return 0;
}
