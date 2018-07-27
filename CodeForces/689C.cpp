/****************
*PID:
*Auth:Jonariguez
*****************
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

LL cal(LL n){
    LL i,j,k,res=0;
    for(k=2;;k++){
        LL temp=k*k*k;
        if(temp>n) break;
        res+=n/temp;
    }
    return res;
}

int main()
{
    LL i,j,n,m;
    while(scanf("%I64d",&m)!=EOF){
        LL l=1,r=1e18,res=0;
        while(l<=r){
            LL mid=l+(r-l)/2;
          //  printf("l=%I64d r=%I64d mid=%I64d\n",l,r,mid);
            if(cal(mid)>=m){
                res=mid;
                r=mid-1;
            }else {
                l=mid+1;
            }
        }
       // printf("res=%I64d\n",res);
        if(res && cal(res)==m)
            printf("%I64d\n",res);
        else printf("-1\n");
    }
    return 0;
}


