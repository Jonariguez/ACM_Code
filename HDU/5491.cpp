/****************
*PID:hdu5491
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
ll bit[40];

ll cal(ll n){
    ll res=0,i,t=1;
    for(i=0;i<=n;i++){
        if(bit[i])
        res+=t;
        t*=2;
    }
    return res;
}


int main()
{
    ll i,j,res,T,n,kcase=1;
    scanf("%lld",&T);
    ll d,s1,s2;
    while(T--){
        scanf("%lld%lld%lld",&d,&s1,&s2);
        printf("Case #%lld: ",kcase++);
        memset(bit,0,sizeof(bit));
        n=d;
        ll cnt=0,tot=0;
        while(d){
            if(d%2){
                bit[tot++]=1;
                cnt++;
            }else
                bit[tot++]=0;
            d/=2;
        }
        if(cnt<s2 && bit[0]==0){
            printf("%lld\n",n+1);
            continue;
        }
        ll cc=0;
        for(i=0;i<tot;i++){
            if(bit[i]==1) cc++;
            if(bit[i]==1 && bit[i+1]==0){
                bit[i]=0;bit[i+1]=1;break;
            }
        }
        cc--;
        i-=1;
        ll c=cnt-max(s1,0LL);
        for(;i>=0;i--) bit[i]=0;
        cc-=c;
        for(j=0;j<cc;j++) bit[j]=1;
        printf("%lld\n",cal(tot));
    }
    return 0;
}

