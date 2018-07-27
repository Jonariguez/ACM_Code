/****************
*ID:poj2115
*Auth:Jonariguez
*****************
同余方程
(A+m*C)==B(mod r)   r=2^k
C*m-n*r=B-A
C->a  m->x  r->b  -n->y  B-A->c 得
a*x+b*y=c  求x
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

int main()
{
    ll i,j,A,B,C,k,a,b,c,d;
    while(scanf("%lld%lld%lld%lld",&A,&B,&C,&k)){
        if(A==0 && B==0 && C==0 && k==0) break;
        b=(ll)pow(2,k);      //别忘了类型强转
        a=C;
        c=B-A;
        ll x,y;
        Ex_gcd(a,b,d,x,y);
        if(c%d){
            printf("FOREVER\n");
            continue;
        }
        ll t=b/d;       //t应该是long long 的，小心溢出
        x=(x*(c/d)%t+t)%t;
        printf("%lld\n",x);
    }
    return 0;
}
