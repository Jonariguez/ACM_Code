/****************
*PID:489d div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=3000+5;
const int maxm=30000+10;
vector<vector<int> > G;
vector<int> g[maxn];
bool mp[maxn][maxn];
int cnt[maxn][maxn];

int main()
{
    int i,j,k,n,m,a,b;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
       // mp[a][b]=1;
        g[a].push_back(b);
    }
    int res=0;
    for(i=1;i<=n;i++){
        //if(g[i].size()<=1) continue;
        for(j=0;j<g[i].size();j++){
            int v=g[i][j];
            for(k=0;k<g[v].size();k++){
                int t=g[v][k];
                if(t!=i)
                    cnt[i][t]++;
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            res+=(cnt[i][j]-1)*cnt[i][j]/2;
        }
    }
    printf("%d\n",res);
    return 0;
}
