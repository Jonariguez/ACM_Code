/****************
*PID:SWUSTOJ626
*Auth:Jonariguez
*****************
°£¼°·ÖÊý
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
    ll a,b,q,r;
    int flag=0;
    scanf("%lld/%lld",&a,&b);
    ll g=gcd(a,b);
    a/=g;b/=g;
    if(a==1){
        printf("1/%lld\n",b);
        return 0;
    }
    while(a!=1){
        q=b/a;r=b%a;
        if(flag) printf(" ");
        flag=1;
        printf("1/%lld",q+1);
        printf(" +");
        a-=r;
        b*=(q+1);
        g=gcd(a,b);
        b/=g;a/=g;
    }
    printf(" 1/%lld\n",b);
    return 0;
}
