/****************
*PID:515c div2
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

const int maxn=100000+10;

int vis[10];

int main()
{
    int i,j,n;
    char num[20];
    while(scanf("%d",&n)!=EOF){
        scanf("%s",num+1);
        i=1;
        while(num[i]=='0') i++;
        memset(vis,0,sizeof(vis));
        for(;i<=n;i++)
            vis[num[i]-'0']++;
        int cnt;
        if(vis[9]){
            cnt=vis[9];
            vis[7]+=cnt*1;vis[3]+=cnt*2;vis[2]+=cnt;
            vis[9]=0;
        }
        if(vis[8]){
            cnt=vis[8];
            vis[7]+=cnt;vis[2]+=cnt*3;vis[8]=0;
        }
        if(vis[6]){
            cnt=vis[6];
            vis[5]+=cnt;vis[3]+=cnt;vis[6]=0;
        }
        if(vis[4]){
            cnt=vis[4];
            vis[3]+=cnt;vis[2]+=cnt*2;vis[4]=0;
        }
        for(i=7;i>1;i--){
            while(vis[i]){
                printf("%d",i);vis[i]--;
            }
        }
        printf("\n");
    }
    return 0;
}
