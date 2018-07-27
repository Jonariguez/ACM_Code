/****************
*PID:poj3660
*Auth:Jonariguez
*****************
由牛之间的两两关系，可以用floyd求传递闭包，确定每两头牛
之间的关系，然后求出每个牛的度。
如果对于一头牛，赢它的牛的个数加上败给它的牛的个数=n-1则它
的rank是确定的
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
const int INF=1e9;
int mp[maxn][maxn],n,m,d[maxn];

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(mp,0,sizeof(mp));
        memset(d,0,sizeof(d));
        int a,b;
        for(i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            mp[a][b]=1;
           // d[b]++;
        }
        for(int k=1;k<=n;k++){
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    if(mp[i][k] && mp[k][j])
                        mp[i][j]=1;
                }
            }
        }
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(mp[i][j]){
                    d[i]++;d[j]++;
                }
        int res=0;
        for(i=1;i<=n;i++)
            if(d[i]==n-1) res++;
        printf("%d\n",res);
    }
    return 0;
}

