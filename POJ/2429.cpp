/****************
*PID:poj2429
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <map>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=200000+10;
vector<int> prime;
bool vis[maxn];

LL random(LL n){
    return (LL)((double)rand()/RAND_MAX*n+0.5);
}

void prime_table(){
    int i,j;
    vis[0]=vis[1]=1;
    for(i=2;i<=200000;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(j=i*2;j<=200000;j+=i) vis[j]=1;
        }
    }
}

LL multi(LL a,LL b,LL m){
    a=(a%m+m)%m;
    b=(b%m+m)%m;
    LL res=0;
    while(b){
        if(b&1) res=(res+a)%m;
        b/=2;
        a=(a*2)%m;
    }
    return res;
}

LL quick_pow(LL a,LL b,LL m){
    a=(a%m+m)%m;
    LL res=1;
    while(b){
        if(b&1) res=multi(res,a,m);
        b/=2;
        a=multi(a,a,m);
    }
    return res;
}

bool test(LL a,LL cnt,LL m,LL n){
    LL x=quick_pow(a,m,n);
    if(x==1 || x==n-1) return false;
    while(cnt--){
        x=multi(x,x,n);
        if(x==n-1) return false;    //通过测试，是强可能素数
    }
    return true;
}

bool isPrime(LL n){
    if(n<=200000) return vis[n]==0;
    if(n%2==0) return false;
    LL m=n-1,cnt=0;
    while(m%2==0){
        cnt++;m/=2;
    }
    for(int i=0;i<20;i++){
        LL a=random(n);
        if(test(a,cnt,m,n))
            return false;
    }
    return true;
}

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

LL pollard_rho(LL n,int c){
    LL x=2,y=2,d=1;
    while(d==1){
        x=multi(x,x,n)+c;
        y=multi(y,y,n)+c;
        y=multi(y,y,n)+c;
        d=gcd(((x-y)>0?(x-y):(y-x)),n);
    }
    if(d==n) return pollard_rho(n,c+1);
    return d;
}

map<LL,int> fact;

void factorize(LL n, map<LL, int>& fact){
    if(isPrime(n)){
        fact[n]++;return ;
    }
    int i;
    for(i=0;i<prime.size();i++){
        int x=prime[i];
        while(n%x==0){
            fact[x]++;n/=x;
        }
    }
    if(n!=1){
        if(isPrime(n))
            fact[n]++;
        else {
            LL d;
            d=pollard_rho(n,1);
            factorize(d,fact);
            factorize(n/d,fact);
        }
    }
}

pair<LL,LL> solve(LL a,LL b){
    LL c=b/a;
    map<LL,int> fact;
    factorize(c,fact);

    vector<LL> mult_fact;
    map<LL,int>::iterator it;
    for(it=fact.begin();it!=fact.end();it++){
        LL mul=1;
        while(it->second){
            mul*=it->first;
            it->second--;
        }
        mult_fact.push_back(mul);
    }

    LL best_sum=1e18,best_x=1,best_y=c;
    for(int mask=0;mask<(1<<mult_fact.size());mask++){
        LL x=1;
        for(int i=0;i<mult_fact.size();i++)
            if(mask&(1<<i)) x*=mult_fact[i];
        LL y=c/x;
        if(x<y && x+y<best_sum){
            best_sum=x+y;
            best_x=x;best_y=y;
        }
    }
    return make_pair(best_x*a,best_y*a);
}

int main()
{
    int i;
    LL GCD,LCM;
    prime_table();
    while(scanf("%I64d%I64d",&GCD,&LCM)!=EOF){
        pair<LL,LL> res=solve(GCD,LCM);
        printf("%I64d %I64d\n",res.first,res.second);
    }
    return 0;
}
