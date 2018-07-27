/****************
*PID:600b
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=200000+10;
int a[maxn],b[maxn];

int main()
{
    int i,j,res,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=0;i<m;i++) scanf("%d",&b[i]);
        sort(a,a+n);
        for(i=0;i<m;i++)
            printf("%d ",upper_bound(a,a+n,b[i])-a);
    }
    return 0;
}
