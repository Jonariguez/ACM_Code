#include<stdio.h>
typedef long long ll;

void Exgcd(ll a,ll b,ll &d,ll &x,ll &y){
    if(b==0){
        x=1;y=0;d=a;return ;
    }
    Exgcd(b,a%b,d,y,x);
    y-=(a/b)*x;
}

ll China(ll *a,ll *r,ll k){
    ll M=1,Mi,i,j,d,x,y,res=0;
    for(i=0;i<k;i++)
        M*=a[i];
    for(i=0;i<k;i++){
        Mi=M/a[i];
        Exgcd(Mi,a[i],d,x,y);
        res=(res+Mi*r[i]*x)%M;
    }
    if(res<=0) res+=M;
    return res;
}

ll quick_pow(ll a,ll b,ll m){
    a%=m;
    ll res=1;
    while(b){
        if(b&1)
            res=(res*a)%m;
        b/=2;
        a=(a*a)%m;
    }
    return res;
}

ll Com(ll n,ll m,ll p){
    if(n<m) return 0;
    if(m==0 || m==n) return 1;
    if(m>n-m) m=n-m;
    ll i,a1=1,b1=1;
    for(i=0;i<m;i++){
        a1=(a1*(n-i)/(i+1))%p;
    }
  //  ll res=quick_pow(b1,p-2,p);
    return (a1)%p;
}

ll Lucas(ll n,ll m,ll p){
    if(m==0) return 1;
    return (Com(n%p,m%p,p)*Lucas(n/p,m/p,p))%p;
}

ll p[12],r[12],a[12];

int main()
{
    ll i,j,T;
    ll n,m,k;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld",&n,&m,&k);
        for(i=0;i<k;i++)
            scanf("%lld",&p[i]);
        for(i=0;i<k;i++){
            r[i]=Lucas(n,m,p[i])%p[i];
        }
        printf("%lld\n",China(p,r,k));
    }
    return 0;
}

