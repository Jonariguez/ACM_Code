/****************
*PID:uva10474
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10000+10;
int a[maxn];

int main()
{
    int i,j,n,m,kcase=1;
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        printf("CASE# %d:\n",kcase++);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        while(m--){
            int x;
            scanf("%d",&x);
            int t=lower_bound(a,a+n,x)-a;
            if(a[t]==x)
                printf("%d found at %d\n",x,(t+1));
            else printf("%d not found\n",x);
        }
    }
    return 0;
}
