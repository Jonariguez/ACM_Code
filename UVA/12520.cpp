/****************
*ID:uva12520
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

ll Pow(ll n){
    return n*n;
}

int main()
{
    ll n,l;
    while(scanf("%lld%lld",&l,&n)){
        if(l==0 && n==0) break;
        if(l==1){
            if(n==0) printf("0\n");
            else printf("4\n");
            continue;
        }
        ll L,most,better,worse;
        if(l%2==0){
            most=l*l/2;
            if(n<=most){
                printf("%lld\n",n*4);
            }else if(n<=most+2){
                printf("%lld\n",most*4);
            }else if(n<=most+2*(l-1))
                printf("%lld\n",most*4-2*(n-most-2));
            else
                printf("%lld\n",most*4-2*(n-most-2)-4*(n-most-2*(l-1)));
        }else {
           most=Pow((l+1)/2)+Pow(l/2);
           printf("most=%lld\n",most);
           if(n<=most)
                printf("%lld\n",n*4);
           else if(n<=most+2*(l-1)){
                n-=most;
                printf("%lld\n",most*4-2*n);
           }else {
                n-=most+2*(l-1);
                printf("%lld\n",most*4-4*(l-1)-n*4);
           }
        }
    }
    return 0;
}
