/****************
*PID:foj2184
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
int vis[maxn],a[maxn];

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        int x;
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            for(j=1;j<=n;j++){
                if(vis[j]) continue;
                if(!x) break;
                x--;
            }
            a[i]=j;vis[j]=1;
        }
        for(i=0;i<n;i++)
            printf("%d%c",a[i],i==n-1?'\n':' ');
    }
    return 0;
}
