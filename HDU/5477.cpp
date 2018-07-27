/****************
*PID:hdu5477
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=110;
int vis[100005];

int main()
{
    int i,j,res,n,T,kcase=1;
    int a,b,l;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&a,&b,&l);
        fill(vis,vis+l+1,b);
        j=0;
        int L,R;
        for(i=0;i<n;i++){
            scanf("%d%d",&L,&R);
            for(j=L;j<R;j++)
                vis[j]=-a;
        }
        vis[0]=b;       //注意，是从0开始
        res=100000000;
        for(i=1;i<l;i++){
            vis[i]+=vis[i-1];
            res=min(res,vis[i]);
        }
        res=min(res,0);
        printf("Case #%d: %d\n",kcase++,-res);
    }
    return 0;
}
