/****************
*ID:poj2891
*Auth:Jonariguez
*****************
一元线性同余方程组
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void Ex_gcd(ll a,ll b,ll &d,ll &x,ll &y){
    if(b==0){
        x=1;y=0;d=a;return ;
    }
    Ex_gcd(b,a%b,d,y,x);
    y-=(a/b)*x;
}

ll solve(int n){
    ll a,b,c,d,x,y,a1,r1,a2,r2;
    int yes=1;
    scanf("%lld%lld",&a1,&r1);
    for(int i=1;i<n;i++){
        scanf("%lld%lld",&a2,&r2);
        a=a1;b=a2;c=r2-r1;
        Ex_gcd(a,b,d,x,y);
        if(c%d)
            yes=0;
        int t=b/d;
        x=(x*(c/d)%t+t)%t;
        r1+=a*x;
        a1=a1/d*b;
    }
    if(!yes)
        r1=-1;
    return r1;
}

int main()
{
    int i,j,n;
    while(~scanf("%d",&n))
        printf("%lld\n",solve(n));
    return 0;
}
