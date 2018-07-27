/*
循环节
一下写出来了，希望1A
*/
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef unsigned long long ll;  //注意这里要用unsigned long long，long long存不下
/*
unsigned   int   0～4294967295
int   2147483648～2147483647
unsigned long 0～4294967295
long   2147483648～2147483647
long long的最大值：9223372036854775807
long long的最小值：-9223372036854775808
unsigned long long的最大值：18446744073709551615

__int64的最大值：9223372036854775807
__int64的最小值：-9223372036854775808
unsigned __int64的最大值：18446744073709551615
*/

const int maxn=1000+5;

ll multi(ll a,ll b,ll MOD){
    a%=MOD;b%=MOD;
    ll res=0;
    while(b){
        if(b&1)
            res=(res+a)%MOD;
        b/=2;
        a=(a*2)%MOD;
    }
    return res;
}

ll quick_pow(ll a,ll b,ll MOD){
    ll res=1;
    a%=MOD;
    while(b){
        if(b&1)
            res=multi(res,a,MOD);
        b/=2;
        a=multi(a,a,MOD);
    }
    return res;
}

int mp[maxn][maxn];
unsigned short f[maxn*maxn];
int t[maxn],start[maxn];

int main()
{
    int T;
    ll i,a,b,n,d;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld",&a,&b,&n);
        if(n==1){
            printf("0\n");continue;
        }
        if(t[n]){
            d=quick_pow(a,b,t[n]);
            printf("%d\n",f[start[n]+d]);
            continue;
        }
        memset(mp,0,sizeof(mp));
        f[0]=0;f[1]=1%n;
        mp[f[0]][f[1]]=1;
        for(i=2;i<=n*n;i++){
            f[i]=(f[i-1]+f[i-2])%n;
            if(mp[f[i-1]][f[i]])
                break;
            mp[f[i-1]][f[i]]=i;
        }
        start[n]=mp[f[i-1]][f[i]]-1;
        t[n]=i-mp[f[i-1]][f[i]];
        d=quick_pow(a,b,t[n]);
        printf("%d\n",f[start[n]+d]);
    }
    return 0;

}

