/****************
*PID:519b div2
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
int a[maxn],b[maxn],c[maxn];

int main()
{
    int i,j,k,n;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        for(i=0;i<n-1;i++)
            scanf("%d",&b[i]);
        sort(b,b+n-1);
        for(i=0;i<n-2;i++)
            scanf("%d",&c[i]);
        sort(c,c+n-2);
        for(i=0;i<n-1;i++)
            if(a[i]!=b[i]) break;
        printf("%d\n",a[i]);
        for(i=0;i<n-2;i++)
            if(b[i]!=c[i]) break;
        printf("%d\n",b[i]);
    }
    return 0;
}
