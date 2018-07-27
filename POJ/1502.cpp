/****************
*PID:poj1502
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
const int INF=1e9;
int dis[maxn][maxn],vis[maxn],d[maxn];

int cal(char *s){
    int n=strlen(s),res=0;
    for(int i=0;i<n;i++){
        res=res*10+(s[i]-'0');
    }
    return res;
}

int Dijkstra(int n){
    int i,j,res=0;
    for(i=1;i<=n;i++) d[i]=INF;
    d[1]=0;
    while(1){
        int v=-1;
        for(i=1;i<=n;i++)
            if(vis[i]==0 && (v==-1 || d[v]>d[i])) v=i;
        if(v==-1) break;
        vis[v]=1;
        res=max(res,d[v]);
        for(i=1;i<=n;i++){
            if(vis[i]==0 && d[v]<INF && d[i]>d[v]+dis[v][i])
                d[i]=d[v]+dis[v][i];
        }
    }
    return res;
}







int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++) dis[i][j]=INF;
        for(i=1;i<=n;i++) dis[i][i]=0;
        char s[40];
        for(i=2;i<=n;i++){
            for(j=1;j<i;j++){
                scanf("%s",s);
                if(s[0]=='x') continue;
                dis[i][j]=dis[j][i]=cal(s);
            }
        }
        printf("%d\n",Dijkstra(n));
    }
    return 0;
}
