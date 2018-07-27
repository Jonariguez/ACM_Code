/****************
*PID:474b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=1000000+5;
int a[maxn],vis[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        j=1;
        for(i=1;i<=n;i++){
            int v=a[i],c=0;
            for(;c<a[i];c++,j++)
                vis[j]=i;
        }
        scanf("%d",&m);
        while(m--){
            int q;
            scanf("%d",&q);
            printf("%d\n",vis[q]);
        }
    }
    return 0;
}
