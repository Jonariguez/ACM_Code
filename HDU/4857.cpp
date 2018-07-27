/****************
*PID:hdu4857
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=30000+10;
int in[maxn];
set<int> ss[maxn];
vector<int> res,G[maxn];
int n;

void bfs(){
    int i,j;
    priority_queue<int> que;
    for(i=1;i<=n;i++)
        if(in[i]==0){
            que.push(i);
        }
    while(!que.empty()){
        int t=que.top();que.pop();
        res.push_back(t);
        for(i=0;i<G[t].size();i++){
            int v=G[t][i];
            in[v]--;
            if(in[v]==0) que.push(v);
        }
    }
}

int main()
{
    int i,j,T,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(in,0,sizeof(in));
        for(i=0;i<=n;i++){
            ss[i].clear();
            G[i].clear();
        }
        for(i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&b,&a);
            if(ss[a].count(b)) continue;
            ss[a].insert(b);
            G[a].push_back(b);
            in[b]++;
        }
        res.clear();
        bfs();
        reverse(res.begin(),res.end());
        for(i=0;i<res.size();i++)
            printf("%d%c",res[i],i==res.size()-1?'\n':' ');
    }
    return 0;
}
