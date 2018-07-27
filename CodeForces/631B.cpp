/****************
*PID:
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=5000+10;
const int maxk=100000+5;
int c[maxn][maxn],col[maxn],row[maxn];
int o[maxk],b[maxk],a[maxk];

int main()
{
    int i,j,n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        memset(col,0,sizeof(col));
        memset(row,0,sizeof(row));
        memset(c,0,sizeof(c));
        for(i=1;i<=k;i++)
            scanf("%d%d%d",&o[i],&b[i],&a[i]);
        for(i=k;i>=1;i--){
            if(o[i]==1){
                if(row[b[i]]==0){
                    for(j=1;j<=m;j++)
                        if(!c[b[i]][j]) c[b[i]][j]=a[i];
                }
                row[b[i]]=1;
            }else {
                if(col[b[i]]==0){
                    for(j=1;j<=n;j++)
                        if(!c[j][b[i]]) c[j][b[i]]=a[i];
                }
                col[b[i]]=1;
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                printf("%d ",c[i][j]);
            }
            puts("");
        }
    }
    return 0;
}
