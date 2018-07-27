/****************
*PID:cf572A
*Auth:Jonariguez
*****************
比较A的第k小和B的第m大就行了
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
int a[maxn],b[maxn],na,nb,m,k;

int main()
{
    int i;
    while(scanf("%d%d",&na,&nb)!=EOF){
        scanf("%d%d",&k,&m);
        for(i=1;i<=na;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=nb;i++)
            scanf("%d",&b[i]);
     //   sort(a,a+na);
     //   sort(b,b+nb);
        if(a[k]<b[nb-m+1])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
