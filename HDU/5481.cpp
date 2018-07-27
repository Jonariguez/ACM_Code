/****************
*PID:hdu5481
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

const int maxn=100000+10;
const int MOD=1000000007;

ll bit[maxn];

struct pp{
    int v,bLeft;
}s[maxn*2];

int cmp(const pp &x,const pp &y){
    if(x.v==y.v)
        return x.bLeft<y.bLeft;
    return x.v<y.v;
}

ll Pow(ll a,ll b){
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
    int i,j,T,n,l,r;
    scanf("%d",&T);
    bit[0]=1;
    for(i=1;i<=100000;i++)
        bit[i]=(bit[i-1]*2)%MOD;
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d",&l,&r);
            s[i*2].v=l;s[i*2].bLeft=1;
            s[i*2+1].v=r;s[i*2+1].bLeft=-1;
        }
        sort(s,s+2*n,cmp);
        ll cover=1,res=0;
        for(i=1;i<2*n;i++){
            res+=(ll)(s[i].v-s[i-1].v)*(bit[n-cover]*(bit[cover]-1)%MOD);
           // res+=(ll)(s[i].v-s[i-1].v)*(bit[n-cover]*(bit[cover]-1)%MOD);
            cover+=s[i].bLeft;
          //  printf("cover=%lld\n",cover);
            if(res>=MOD)
                res-=MOD;
        }
        res%=MOD;
        if(res<0)
            res+=MOD;
        printf("%lld\n",res);
    }
    return 0;
}
