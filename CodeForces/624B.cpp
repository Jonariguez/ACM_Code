/****************
*PID:624b div2
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

const int maxn=100;
LL a[maxn];

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++) scanf("%I64d",&a[i]);
        sort(a+1,a+n+1);
        LL now=a[n]-1;
        LL res=a[n];
        for(i=n-1;i>0;i--){
            if(now==0) break;
            res+=min(now,a[i]);
            now=min(now,a[i]);
            now--;
        }
        printf("%I64d\n",res);
    }
    return 0;
}
