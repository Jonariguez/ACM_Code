/****************
*PID:485a div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int vis[1000005];

int main()
{
    int i,j,a,m;
    while(scanf("%d%d",&a,&m)!=EOF){
        memset(vis,0,sizeof(vis));
        int yes=1;

        while((a%m)!=0){
            int t=a%m;
            if(vis[t]==1){
                yes=0;break;
            }
            vis[t]=1;//printf("??\n");
            a+=t;
            a%=m;
        }
        if(yes) puts("Yes");
        else puts("No");
    }
    return 0;
}
