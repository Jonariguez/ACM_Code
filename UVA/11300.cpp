/****************
*PID:uva11300
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

const int maxn=1000000+10;

LL a[maxn],c[maxn];

int main()
{
    int i,j,n,M;
    while(scanf("%d",&n)!=EOF){
        ULL sum=0;
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        M=sum/n;
        a[0]=0;
        for(i=1;i<n;i++)
            a[i]=a[i-1]+a[i]-M;
        sort(a,a+n);
        LL x=a[n/2],res=0;
        for(i=0;i<n;i++)
            res+=abs(x-a[i]);
        printf("%lld\n",res);
    }
    return 0;
}


