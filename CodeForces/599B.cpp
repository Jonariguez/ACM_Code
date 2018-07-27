/****************
*PID:599b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
int vis[maxn],cnt[maxn];
int f[maxn],b[maxn],res[maxn];

int main()
{
    int i,j,n,k,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(vis,0,sizeof(vis));
        memset(cnt,0,sizeof(cnt));
        for(i=1;i<=n;i++){
            scanf("%d",&f[i]);
            vis[f[i]]=i;
            cnt[f[i]]++;
        }
        for(i=1;i<=m;i++)
            scanf("%d",&b[i]);
        int yes=1;
        for(i=1;i<=m;i++){
            int x=b[i];
            if(cnt[b[i]]>=2){
                yes=2;
            }else if(cnt[b[i]]==0){
                yes=0;break;
            }else res[i]=vis[b[i]];
        }
        if(yes==0)
            printf("Impossible\n");
        else if(yes==2)
            printf("Ambiguity\n");
        else {
            printf("Possible\n");
            for(i=1;i<=m;i++)
                printf("%d ",res[i]);
            printf("\n");
        }
    }
    return 0;
}
