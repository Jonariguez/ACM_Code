/****************
*PID:492b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
int a[maxn];

int main()
{
    int i,j,n,l;
    while(scanf("%d%d",&n,&l)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        double d=(double)a[1];
        for(i=2;i<=n;i++)
            d=max(d,(double)(a[i]-a[i-1])/2);
        d=max(d,(double)l-a[n]);
        printf("%.10f\n",d);
    }
    return 0;
}
