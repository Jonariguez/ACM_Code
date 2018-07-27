/****************
*PID:uva11388
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

int main()
{
    int i,T;
    ll n,L,G;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&G,&L);
        if(L%G)
            printf("-1\n");
        else
            printf("%lld %lld\n",G,L);
    }
    return 0;
}
