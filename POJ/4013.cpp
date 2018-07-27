/****************
*PID:poj4013
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
    int i,j,n;
    while(scanf("%d",&n)){
        if(n==0) break;
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        if(n&1)
            printf("%d\n",a[(n+1)/2-1]);
        else printf("%d\n",(a[n/2-1]+a[n/2])/2);
    }
    return 0;
}
