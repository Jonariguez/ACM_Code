/****************
*PID:hdu1907
*Auth:Jonariguez
*****************
≤©ﬁƒ
±ÿ ‰Ã¨”–£∫  T2,S0
±ÿ §Ã¨£∫    S2,S1,T0,T1.
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
int a[maxn];

int main()
{
    int i,j,n,T,res;
    sc(T);
    while(T--){
        sc(n);
        res=0;
        int sum=0;
        for(i=1;i<=n;i++){
            sc(a[i]);
            sum^=a[i];
            if(a[i]>1) res++;
        }
        if(n==1){
            if(a[1]>1) puts("John");
            else puts("Brother");
        }else {
            if(sum==0){     //TÃ¨
                if(res>=2)
                    puts("Brother");
                else puts("John");
            }else {         //SÃ¨
                if(res==0)
                    puts("Brother");
                else puts("John");
            }
        }
    }
    return 0;
}
