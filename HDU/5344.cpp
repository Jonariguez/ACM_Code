/****************
*PID:hdu5344
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

const int maxn=500000+10;
LL a[maxn];

int main()
{
    int T;
    LL m,z,l,n;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d%I64d%I64d%I64d",&n,&m,&z,&l);
        a[1]=0;
        for(LL i=2;i<=n;i++) a[i]=(a[i-1]*m+z)%l;
        LL res=0;
        for(LL i=1;i<=n;i++){
            res^=(a[i]*2);
        }
        printf("%I64d\n",res);
    }
    return 0;
}
