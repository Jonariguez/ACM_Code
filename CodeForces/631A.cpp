/****************
*PID:
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000+10;
int a[maxn],b[maxn],sum1[maxn],sum2[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        LL res=0,t1=0,t2=0;
        sum1[0]=sum2[0]=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            t1|=a[i];
        }
        for(i=1;i<=n;i++){
            scanf("%d",&b[i]);
            t2|=b[i];
        }
        printf("%I64d\n",t1+t2);
    }
    return 0;
}
