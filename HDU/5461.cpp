/****************
*PID:
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

const int maxn=5000000+5;
ll s[maxn];

int cmp1(ll a,ll b){
    return fabs(a)<fabs(b);
}

int cmp2(ll a,ll b){
    return fabs(a)>fabs(b);
}

int main()
{
    int i,j,T,n,kcase=1;
    ll a,b,res;
    scanf("%d",&T);
    while(T--){
        scanf("%d%lld%lld",&n,&a,&b);
        res=0;
        for(i=0;i<n;i++)
            scanf("%lld",&s[i]);
        if(a<0){
            sort(s,s+n,cmp1);
            res=a*s[0]*s[0];
        }else {
            sort(s,s+n,cmp2);
            res=a*s[0]*s[0];
        }
        sort(s+1,s+n);
        if(b>0)
            res+=b*s[n-1];
        else
            res+=b*s[1];
        printf("Case #%d: %lld\n",kcase++,res);
    }
    return 0;
}
