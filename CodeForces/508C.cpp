/****************
*PID:508c div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=300+10;
int w[maxn],vis[maxn];

int main()
{
    int i,j,m,t,r;
    while(scanf("%d%d%d",&m,&t,&r)!=EOF){
        for(i=1;i<=m;i++)
            scanf("%d",&w[i]);
        if(r>t){
            printf("-1\n");continue;
        }
        memset(vis,0,sizeof(vis));
        int res=0;
        for(i=1;i<=m;i++){
            int cnt=vis[i];
            if(cnt>=r) continue;
            cnt=r-cnt;
            res+=cnt;
            for(j=1;j<=cnt;j++){
                int start=w[i]-j;
                int End=start+t;
                for(int k=i+1;k<=m;k++){
                    if(w[k]>End) break;
                    vis[k]++;
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
