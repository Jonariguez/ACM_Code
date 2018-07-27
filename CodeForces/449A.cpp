/****************
*PID:449a div1
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

int main()
{
    LL i,j,n,m,k;
    while(scanf("%I64d%I64d%I64d",&n,&m,&k)!=EOF){
        if((n-1)+(m-1)<k){
            puts("-1");continue;
        }
        if(n>m) swap(n,m);
        LL res=1,t=k;
        if(t<n)
            res=max(res,m*(n/(t+1)));
        else {
            t-=n-1;
            res=max(res,m/(t+1));
        }
        t=k;
        if(t<m)
            res=max(res,n*(m/(t+1)));
        else {
            t-=m-1;
            res=max(res,n/(t+1));
        }
      //  LL res=);
      //  res=max(res,n*(m/(k+1)));
        printf("%I64d\n",res);
    }
    return 0;
}
