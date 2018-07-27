/****************
*PID:
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

ll mul_mod(ll a,ll b,ll m){
    a%=m;
    ll res=0;
    while(b){
        if(b&1)
            res=(res+a)%m;
        b/=2;
        a=(a+a)%m;
    }
    return res;
}

ll Pow(ll a,ll b,ll m){
    a%=m;
    ll res=1;
    while(b){
        if(b&1)
            res=mul_mod(res,a,m);
        b/=2;
        a=mul_mod(a,a,m);
    }
    return res;
}

void Exgcd(ll a,ll b,ll &d,ll &x,ll &y){
    if(b==0){
        x=1;y=0;d=a;return ;
    }
    Exgcd(b,a%b,d,y,x);
    y-=(a/b)*x;
}

ll inv(ll a,ll n){
    ll d,x,y;
    Exgcd(a,n,d,x,y);
    return d==1?(x+n)%n:-1;
}

ll solve2(ll a,ll b,ll n){
    ll m,v,e=1,i;
    m=(ll)sqrt(n+0.5);
    v=inv(Pow(a,m,n),n);
    map<ll,ll> x;
    x[1]=0;
    for(i=1;i<m;i++){
        e=mul_mod(e,a,n);
        if(!x.count(e))
            x[e]=i;
    }
    for(i=0;i<m;i++){
        if(x.count(b))
            return i*m+x[b];
        b=mul_mod(b,v,n);
    }
    return -1;
}






ll solve(ll a,ll m){
    map<ll,ll> rec;
    ll s=(ll)(sqrt((double)m));
    while(s*s<=m)
        s++;
    ll i,cur=1;
    for(i=0;i<s;i++){
        rec[cur]=i;
        cur=cur*a%m;
    }
    ll mul=cur;
    cur=1;
    for(i=0;i<s;i++){
        if(rec.count(0))
            return i*s+rec[0];
        cur=cur*mul%m;
    }
    return -1;
}

int main()
{
    ll a,m;
    while(scanf("%lld%lld",&a,&m)){
        printf("%lld\n",solve2(a,0,m));
    }
    return 0;
}
