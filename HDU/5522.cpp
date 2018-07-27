/****************
*PID:hdu5522
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
int a[maxn],vis[1005];

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            vis[a[i]]=i;
        }
        int flag=1;
        for(i=1;i<n;i++){
            for(j=i+1;j<=n;j++){
                int u=abs(a[i]-a[j]);
                if(vis[u] && vis[u]!=i && vis[u]!=j){
                    flag=0;break;
                }
            }
        }
        if(!flag)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
