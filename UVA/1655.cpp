/****************
*ID:uva1655
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll pow2(ll n){
    ll m=pow(n,0.5);
    while(m*m<=n) m++;
    while(m*m>n) m--;
    return m;
}

ll pow3(ll n){
    ll m=pow(n,1.0/3);
    while(m*m*m<=n) m++;
    while(m*m*m>n) m--;
    return m;
}

int main()
{
    int kcase=1;
    ll n;
    while(scanf("%lld",&n)!=EOF){
        ll m=pow3(n),res=m;
        int i;
        for(i=1;i<=m;i++){
            ll t=n/i,k=pow2(t);
            res+=(t/i+k-i*2)*3;
            for(int j=i+1;j<=k;j++)
                res+=(t/j-j)*6;
        }
        printf("Case %d: %lld\n",kcase++,res);
    }
    return 0;
}
