/****************
*ID:uva10603
*Auth:Jonariguez
*****************
这里不是次数最少，而是倒水量最少，所以bfs时
不用队列，而是优先队列，并且是以从一开始到
现在的倒水量dist作为关键字,类似于Dijkstra算法
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn=220;
int vis[maxn][maxn],ans[maxn],cap[3];

struct Node{
    int v[3],dist;
    bool operator < (const Node& rhs) const {
        return dist>rhs.dist;
    }
};

void solve(int a,int b,int c,int d){
    memset(vis,0,sizeof(vis));
    memset(ans,-1,sizeof(ans));
    cap[0]=a;cap[1]=b;cap[2]=c;
    int i,j;
    Node start;
    start.v[0]=0;start.v[1]=0;start.v[2]=c;
    start.dist=0;
    vis[0][0]=1;
    priority_queue<Node> que;
    que.push(start);
    while(!que.empty()){
        Node u=que.top();que.pop();
        for(i=0;i<3;i++){
            int t=u.v[i];
            if(ans[t]<0 || ans[t]>u.dist)
                ans[t]=u.dist;
        }
        if(ans[d]>=0) break;        //结果已经出来了
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(j==i) continue;
                if(u.v[i]==0 || u.v[j]==cap[j]) continue;
                int delta=min(cap[j],u.v[i]+u.v[j])-u.v[j];
                Node t;
                memcpy(&t,&u,sizeof(u));
                t.v[i]-=delta;
                t.v[j]+=delta;
                t.dist=u.dist+delta;
                if(vis[t.v[0]][t.v[1]]==0){
                    vis[t.v[0]][t.v[1]]=1;
                    que.push(t);
                }
            }
        }
    }
    while(d>=0){
        if(ans[d]>=0){
            printf("%d %d\n",ans[d],d);
            return ;
        }
        d--;    //找小于等于d的且最接近d的，就是从d一直--，遇到合适的就输出
    }
}

int main()
{
    int i,j,T,a,b,c,d;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        solve(a,b,c,d);
    }
    return 0;
}
