/****************
*ID:hdu1788
*Auth:Jonariguez
*****************
N%Mi=Mi-a
->  N%Mi+a=Mi
->  N+a == 0(mod Mi)
则是求(N+a)为所有Mi的lcm，然后-a得N
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    ll i,j,m,a,n,res;
    while(scanf("%lld%lld",&n,&a)){
        if(n==0 && a==0) break;
        res=1;
        for(i=0;i<n;i++){
            scanf("%lld",&m);
            res=res/gcd(res,m)*m;
        }
        printf("%lld\n",res-a);
    }
    return 0;
}
