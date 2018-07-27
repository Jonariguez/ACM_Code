#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100+10;
int n,m,tot;
int Indegree[maxn],Outdegree[maxn],s[maxn];
int vis[maxn][maxn];

void top(){
    queue<int> que;
    for(int i=1;i<=n;i++)
        if(Indegree[i]==0)
            que.push(i);
    tot=0;
    while(!que.empty()){
        int t=que.front();que.pop();
        s[tot++]=t;
        for(int i=1;i<=n;i++)
            if(vis[t][i] && --Indegree[i]==0)
                que.push(i);
    }
}


int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        int a,b;
        memset(Outdegree,0,sizeof(Outdegree));
        memset(Indegree,0,sizeof(Indegree));
        memset(vis,0,sizeof(vis));
        for(i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            vis[a][b]++;
            Outdegree[a]++;
            Indegree[b]++;
        }
        top();
        for(i=0;i<tot;i++)
            printf("%d%c",s[i],i==tot-1?'\n':' ');
    }
    return 0;
}
