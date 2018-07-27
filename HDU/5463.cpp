/****************
*PID:hdu5463
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
int vis[550];

int main()
{
    int i,j,n,res;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int a,b;
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            vis[a]+=b;
        }
        res=0;
        for(i=1;i<=500;i++)
            res+=(vis[i]+63)/64;
        printf("%d\n",(res+35)/36);
    }
    return 0;
}
