/****************
*PID:621a div2
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
const int INF=1e9+7;
LL a[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        LL sum=0,now=INF;
        for(i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
            sum+=a[i];
            if(a[i]&1)
                now=min(now,a[i]);
        }
        if(sum%2==0)
            printf("%I64d\n",sum);
        else printf("%I64d\n",sum-now);
    }
    return 0;
}
