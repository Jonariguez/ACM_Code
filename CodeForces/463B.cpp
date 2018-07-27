/****************
*PID:463b div2
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
int a[maxn];

int main()
{
    int i,j,n,s;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        a[0]=0;
        LL res=1e18,now=0;
        for(i=0;i<n;i++){
            now+=a[i]-a[i+1];
            res=min(res,now);
        }
        printf("%I64d\n",-res);
    }
    return 0;
}
