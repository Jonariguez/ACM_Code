/****************
*PID:la4255
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10+5;
int n,G[maxn][maxn],par[maxn],in[maxn],vis[maxn],c[maxn];
char mp[maxn][maxn],str[maxn*maxn];
vector<int> topo;

int findset(int x){
    return par[x]==x?x:par[x]=findset(par[x]);
}


bool dfs(int u){
    c[u]=-1;
    for(int i=0;i<=n;i++){
        if(G[u][i]){
            if(c[i]<0) return false;
            else if(c[i]==0)
                dfs(i);
        }
    }
    c[u]=1;topo.push_back(u);
    return true;
}

bool toposort(){
    topo.clear();
    memset(c,0,sizeof(c));
    for(int i=0;i<=n;i++)
        if(c[i]==0){
            if(!dfs(i)) return false;
        }
    reverse(topo.begin(),topo.end());
    return true;
}


int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%s",&n,str+1);
        for(i=0;i<=n;i++)
            par[i]=i;
        memset(G,0,sizeof(G));
        int cur=1;
        for(i=1;i<=n;i++){
            for(j=i;j<=n;j++){
                mp[i][j]=str[cur++];
                if(mp[i][j]=='0')
                    par[j]=i-1;
            }
        }
        memset(in,0,sizeof(in));
        for(i=1;i<=n;i++){
            for(j=i;j<=n;j++){
                if(mp[i][j]=='+'){
                    G[findset(i-1)][findset(j)]=1;
                }
                if(mp[i][j]=='-'){
                    G[findset(j)][findset(i-1)]=1;
                }
            }
        }
        toposort();
        int sum[maxn];
        cur=0;
        for(i=0;i<=n;i++) sum[topo[i]]=cur++;
        for(i=1;i<=n;i++){
            sum[i]=sum[findset(i)];
            if(i>1) printf(" ");
            printf("%d",sum[i]-sum[i-1]);
        }
        puts("");
    }
    return 0;
}




