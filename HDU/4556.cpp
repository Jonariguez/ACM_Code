/****************
*PID:hdu4556
*Auth:Jonariguez
*****************
考虑半边，求出个数*2+1即为答案。
半边是分母小于等于x的真分数的个数，即x的欧拉函数值。
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
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=1000000+10;
int phi[maxn];
LL f[maxn];

void table(){
    phi[1]=1;
    for(int i=2;i<=1000000;i++){
        if(!phi[i]){
            for(int j=i;j<=1000000;j+=i){
                if(!phi[j]) phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}

int main()
{
    int i,j,n;
    table();
    f[0]=0;
    LL sum=0;
    for(i=1;i<=1000000;i++){
        sum+=phi[i];
        f[i]=sum*2+1;
    }
    while(scanf("%d",&n)!=EOF){
        printf("%I64d\n",f[n]);
    }
    return 0;
}





