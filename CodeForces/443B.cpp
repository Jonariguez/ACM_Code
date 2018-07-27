/****************
*PID:443b div2
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

const int maxn=200+10;
char str[maxn];

int main()
{
    int i,j,n,res,k;
    scanf("%s",str+1);
    sc(k);
    n=strlen(str+1);
    if(n<=k){
        printf("%d\n",(n+k)/2*2);return 0;
    }
    int m=n;
    n+=k;
    int s,e,stop=0;
    res=2*k;
    for(s=1;s<=m;s++){
        for(e=m;e>=s;e--){
            if(2*e-s-1>n) continue;
           // if(2*(e-s)<=res){
           //     stop=1;break;
          //  }
            int yes=1;
            i=s;j=e;
            while(i<e && j<=m){
                if(str[i]==str[j]){
                    i++;j++;
                }else{
                    yes=0;break;
                }
            }
            if(yes)
                res=max(res,2*(e-s));
        }
       // if(stop==1) break;
    }
    pfn(res);
    return 0;
}


