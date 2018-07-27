/****************
*PID:
*Auth:Jonariguez
*****************
做题在想不到合适的贪心策略，或者想不到具体的方案时，
就不要拘泥于具体怎么样，而是用守恒的思想去做。
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

const int maxn=2000+10;
const int MOD=1e9+7;

LL a[maxn];
int n,k;

bool C(LL x){   //检查是否够满足x个人的
    LL sum=0;
    for(int i=1;i<=n;i++)
        if(a[i]>x) sum+=x;  //如果比x个多，那么它的贡献最多就是x个
        else sum+=a[i];     //否则，它可以贡献所有。
    return (x*k<=sum);      //在这里，我们不纠结它们具体是分配的，但是它们就是能提供这么多
}                           //换句话说，就是把数量求出来就好，总归是有办法分配的！！！！！

int main()
{
    int i,j,T;
    scanf("%d",&T);
    int kcase=1;
    while(T--){
        scanf("%d%d",&n,&k);
        for(i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
        }
        LL res=0;
        LL l=0,r=10000000000000LL;
        while(l<r){
            LL m=(l+r)/2;
            if(C(m)){
                res=m;
                l=m+1;
            }else r=m-1;
        }
        while(C(res+1)) res++;
        printf("Case %d: %I64d\n",kcase++,res);
    }
    return 0;
}

