/****************
*PID:la3521
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

int main()
{
    LL i,j,n,k;
    while(scanf("%lld%lld",&n,&k)!=EOF){
        LL res=0;
        i=1;
        while(i<=n){
            LL p=k/i,q=k%i,cnt;
            if(p==0)
                j=n;
            else j=i+q/p;
            if(j>n) j=n;
            cnt=j-i+1;
            res+=cnt*q-cnt*(cnt-1)/2*p;
            i=j+1;
        }
        printf("%lld\n",res);
    }
    return 0;
}
