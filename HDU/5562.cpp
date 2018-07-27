/****************
*PID:hdu5562
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
int a[maxn];

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        LL res=0;
        for(i=0;i<n;i++)
            if(a[i]<=m){
                res++;m-=a[i];
            }else break;
        printf("%I64d\n",res);
    }
    return 0;
}
