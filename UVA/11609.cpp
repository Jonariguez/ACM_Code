/****************
*PID:uva11609
*Auth:Jonariguez
*****************
C(n,i)*C(i,1)=C(n,1)*C(n-1,i-1)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MOD=1000000007;

ll pow_mod(ll a,ll b){
    a%=MOD;
    ll res=1;
    while(b){
        if(b&1)
            res=(res*a)%MOD;
        b/=2;
        a=(a*a)%MOD;
    }
    return res;
}

int main()
{
    int i,j,T,kcase=1;
    scanf("%d",&T);
    ll n;
    while(T--){
        scanf("%lld",&n);
        ll res=n%MOD;
        res*=pow_mod(2,n-1);
        printf("Case #%d: %lld\n",kcase++,res%MOD);
    }
    return 0;
}
