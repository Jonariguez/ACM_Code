/****************
*PID:534c div2
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

const int maxn=200000+10;
LL a[maxn];

int main()
{
    LL i,j,t,n,A;
    while(scanf("%I64d%I64d",&n,&A)!=EOF){
        LL sum=0;
        for(i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
            sum+=a[i];
        }
        for(i=1;i<=n;i++){
            printf("%I64d",max(a[i]-(A-(n-1)),0LL)+max(A-(sum-a[i])-1,0LL));
            if(i<n) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
