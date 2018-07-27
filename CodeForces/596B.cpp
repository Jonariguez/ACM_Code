/****************
*PID:596b div2
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
int a[maxn],b[maxn];

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        LL res=0,now=0;
        for(i=1;i<=n;i++){
            res+=abs(now-a[i]);
            now=a[i];
        }
        printf("%I64d\n",res);
    }
    return 0;
}
