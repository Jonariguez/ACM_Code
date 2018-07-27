#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
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
const int maxn=1000+10;

vector<int> fib[maxn];

void init(){
    int i,a,b,c;
    for(i=2;i<=1000;i++){
        int mod=i;
        a=0;b=1;c=(a+b)%mod;
        fib[i].push_back(a);
        fib[i].push_back(b);
        fib[i].push_back(c);
        while(!(b==0 && c==1)){
            a=b;b=c;
            c=(a+b)%mod;
            fib[i].push_back(c);
        }
        fib[i].pop_back();fib[i].pop_back();
    }
}

ll power_mod(ll a,ll b,ll m){
    a%=m;
    ll res=1;
    while(b){
        if(b&1) res=(res*a)%m;
        a=(a*a)%m;
        b/=2;
    }
    return res;
}

int main()
{
    int i,j,n,T;
    ll a,b;
    int MOD;
    init();
    scanf("%d",&T);
    while(T--){
        scanf("%llu%llu%d",&a,&b,&MOD);
        if(MOD==1){
            printf("0\n");continue;
        }
        ll d=power_mod(a,b,(ll)fib[MOD].size());
        printf("%d\n",fib[MOD][d]);
    }
    return 0;
}
