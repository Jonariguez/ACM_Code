/****************
*PID:
*Auth:Jonariguez
*****************
号舵籾。。。。
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("d",&x,&y)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#define MP make_pair
#define X first
#define Y second
#define PI acos(-1.0)
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
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=200000+10;
const int MOD=1e9+7;

LL fact[maxn],a[maxn],E[maxn];

LL Pow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%MOD;
        b/=2;
        a=a*a%MOD;
    }
    return res;
}

LL Com(LL n,LL m){
    if(m==0 || n==m) return 1LL;
    LL temp=fact[m]*fact[n-m]%MOD;
    LL inv=Pow(temp,MOD-2);
    return fact[n]*inv%MOD;
}

int main()
{
    int i,j,n;
    fact[0]=1;
    for(i=1;i<=200000;i++)
        fact[i]=fact[i-1]*i%MOD;
    scanf("%d",&n);
    a[2]=0;
    for(i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    if(n<=2){
        printf("%I64d\n",(a[1]+a[2])%MOD);return 0;
    }
    if(n&1){
        for(i=1;i<n;i++)
            if(i&1) a[i]+=a[i+1];
            else a[i]-=a[i+1];
        n--;
    }
    LL N=n/2-1;
    LL sum1=0,sum2=0;
    for(i=0;i<=N;i++)
        E[i]=Com(N,i);
    j=0;
    for(i=1;i<=n;i+=2){
        sum1+=E[j]*a[i]%MOD;
        j++;
        sum1%=MOD;
    }
    j=0;
    for(i=2;i<=n;i+=2){
        sum2+=E[j]*a[i]%MOD;
        j++;
        sum2%=MOD;
    }
    if(n%4)
        sum1+=sum2;
    else sum1-=sum2;
    sum1%=MOD;
    if(sum1<0) sum1+=MOD;
    printf("%I64d\n",sum1);
    return 0;
}

