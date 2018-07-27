/****************
*PID:hdu5567
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
int a[maxn];

int main()
{
    int i,j,res,n,b,c;
    while(scanf("%d%d%d",&n,&b,&c)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        res=0;
        for(i=2;i<=n;i++){
            for(j=1;j<i;j++)
                if((int)fabs(a[j]-a[i])%b==c) res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
