/****************
*PID:hdu2335
*Auth:Jonariguez
*****************
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

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        LL i,j,n,ansx,ansy;
        scanf("%I64d",&n);
        n=(n+4)/5;
        LL k=(LL)sqrt(n+0.5)+2;
        LL res=1e18,w,h,temp;
        for(i=1;i<=k;i++){
            if(i>n) break;
            w=i*40+(i+1)*4;
            temp=(n+i-1)/i;
            h=temp*8+(temp+1)*2;
            if(res>w*h || res==w*h && abs(ansx-ansy)>abs(w-h)){
                res=w*h;
                ansx=w;ansy=h;
            }
        }
        for(i=1;i<=k;i++){
            if(i>n)
                break;
            w=i*8+(i+1)*2;
            temp=(n+i-1)/i;
            h=temp*40+(temp+1)*4;
            if(res>w*h || res==w*h && abs(ansx-ansy)>abs(w-h)){
                res=w*h;
                ansx=w;ansy=h;
            }
        }
        if(ansx<ansy)
            swap(ansx,ansy);
        printf("%I64d X %I64d = %I64d\n",ansx,ansy,res);
    }
    return 0;
}


