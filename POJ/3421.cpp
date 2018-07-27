/****************
*PID:poj3421
*Auth:Jonariguez
*****************
答案二：
只要把它们排好了，顺序乘起来就能得到一条独一无二的链。（前缀积）
个数就是有重复元素的排列
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

const int maxn=100000+10;

LL cal(LL n){
    LL res=1;
    for(LL i=2;i<=n;i++) res*=i;
    return res;
}

int main()
{
    LL i,j,n,res,ans;
    while(scanf("%I64d",&n)!=EOF){
        res=0;ans=1;
        for(i=2;i*i<=n;i++){
            if(n%i==0){
                LL cnt=0;
                while(n%i==0){
                    n/=i;cnt++;
                }
                res+=cnt;ans*=cal(cnt);
            }
        }
        if(n!=1){
            res++;
        }
        printf("%I64d %I64d\n",res,cal(res)/ans);
    }
    return 0;
}


