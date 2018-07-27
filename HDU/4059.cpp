/****************
*PID:hdu4059
*Auth:Jonariguez
*****************
前i个数的4次方之后公式+容斥原理
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef int Ll;
//Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000000+1;
const LL MOD=1e9+7;
//bool vis[maxn];
//int sum[maxn];//val[maxn];
//int cnt[100000];

vector<LL> prime,p;

LL quick_pow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=(res*a)%MOD;
        b/=2;
        a=(a*a)%MOD;
    }
    return res;
}

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

LL inv;
//前n项4次方之和。
LL cal(LL n){
    LL ans=n;
    ans=(ans*(n+1))%MOD;
    ans=(ans*((2*n+1)%MOD))%MOD;
    ans=(ans*(((3*n*n)%MOD+(3*n)%MOD-1+MOD)%MOD))%MOD;
    ans=(ans*inv)%MOD;
    return ans;
}


int main()
{
    LL i,j,n,m,T;
    inv=quick_pow(30LL,MOD-2);
    scanf("%I64d",&T);
    while(T--){
        scanf("%I64d",&n);
        LL res=0;
        res=cal(n);
        p.clear();
        LL x,temp=n;
        for(i=2;i*i<=n;i++){
            if(n%i==0){
                p.push_back(i);
                while(n%i==0) n/=i;
            }
        }
        if(n!=1) p.push_back(n);
        n=temp;
        m=(LL)p.size();
        LL cnt,lcm;
        for(LL mask=1;mask<(1<<m);mask++){
            cnt=0;lcm=1;
            for(i=0;i<m;i++){
                if((mask>>i)&1){
                    cnt++;
                    lcm=lcm/gcd(lcm,p[i])*p[i];
                    if(lcm>n) break;
                }
            }
            if(i<m) continue;
          //  printf("cnt=%I64d lcm=%I64d\n",cnt,lcm);
            if(cnt%2==0){
                res+=quick_pow(lcm,4)*cal(n/lcm)%MOD;
                res%=MOD;
            }else {
                res-=quick_pow(lcm,4)*cal(n/lcm)%MOD;
                res%=MOD;
            }
        }
        if(res<0) res+=MOD;
        printf("%I64d\n",res);
    }
    return 0;
}



