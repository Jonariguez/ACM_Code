#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 1e18
#define debug(x) printf("x=%d\n",x)
typedef long long ll;


int main()
{
    int i,j,n,k,a[20],kcase=1,flag=0;
    ll maxv=-INF-1;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        ll sum=0;
        maxv=-INF-1;
        for(i=1;i<=n;i++){
            for(j=i;j<=n;j++){
                ll sum=1;
                for(k=i;k<=j;k++)
                    sum*=a[k];
                maxv=max(maxv,sum);
            }
        }
        if(maxv<0)
            printf("Case #%d: The maximum product is 0.\n\n",kcase++);
        else
            printf("Case #%d: The maximum product is %lld.\n\n",kcase++,maxv);
    }
    return 0;
}
