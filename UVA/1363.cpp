/*
P338
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

//首项为a，公差为d，项数为n，求和
ll sum(ll a,ll d,ll n){
    return a*n+d*n*(n-1)/2;
}

int main()
{
    ll i,j,n,k;
    while(scanf("%lld%lld",&n,&k)!=EOF){
        ll res=0;
        i=1;
        while(i<=n){
            ll p=k/i,q=k%i;
            ll cnt=n-i;
            if(p)           //如果p=0，则不会执行这一步，即cnt就会=n-i，这个时候也就是等差数列延续到最后
                cnt=min(cnt,q/p);
            res+=sum(q,-p,cnt+1);
            i+=cnt+1;
        }
        printf("%lld\n",res);
    }
    return 0;
}
