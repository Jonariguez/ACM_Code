/****************
*PID:uva10763
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=500000+10;

int vis[1010][1010];

int main()
{
    int i,j,n;
    while(scanf("%d",&n),n){
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            vis[a][b]++;
        }
        int yes=1;
        for(i=1;i<=1000;i++)
            for(j=1;j<=i;j++)
                if(vis[i][j]!=vis[j][i]){
                    yes=0;break;
                }
        if(yes)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
