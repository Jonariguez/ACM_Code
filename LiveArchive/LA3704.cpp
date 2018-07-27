/****************
*PID:la3704
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=500+10;
typedef long long Matrix[maxn];
LL MOD,n;

void Multi(Matrix A,Matrix B,Matrix C){
    Matrix res;
    LL i,j;
    for(i=0;i<n;i++){
        res[i]=0;
        for(j=0;j<n;j++)
            res[i]=(res[i]+A[j]*B[(i-j+n)%n])%MOD;
    }
    memcpy(C,res,sizeof(res));
}

void quick_pow(Matrix A,LL N,Matrix C){
    Matrix res;
    memset(res,0,sizeof(res));
    res[0]=1;
    while(N){
        if(N&1)
            Multi(res,A,res);
        N/=2;
        Multi(A,A,A);
    }
    memcpy(C,res,sizeof(res));
}


int main()
{
    LL i,j,m,d,k;
    while(scanf("%lld%lld%lld%lld",&n,&m,&d,&k)!=EOF){
        MOD=m;
        Matrix t,res,v;
        for(i=0;i<n;i++)
            t[i]=min(i,n-i)<=d?1:0;
        for(i=0;i<n;i++){
            scanf("%lld",&v[i]);
            v[i]%=MOD;
        }
        quick_pow(t,k,res);
        Multi(v,res,t);
        for(i=0;i<n;i++)
            printf("%lld%c",t[i],i==n-1?'\n':' ');
    }
    return 0;
}
