/****************
*PID:431d div2
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
LL m,k;

LL Com(LL n,LL m){
    if(m==0) return 1LL;
    LL res=n--,i;
    for(i=2;i<=m;i++){
        res*=n;res/=i;
        n--;
    }
    return res;
}


LL cal(LL n){
    LL res=0,i,cnt=0;
    for(i=62;i>=0;i--){
        if((n>>i)&1){
            if(k-cnt>=0)
                res+=Com(i,k-cnt);
            cnt++;
        }
    }
    return res;
}


int main()
{
    int i,j;
    while(scanf("%I64d%I64d",&m,&k)!=EOF){
        LL l=1,r=1e18,Mid,res=-1;
        while(l<r-1){
            Mid=l+(r-l)/2;
            LL temp=cal(2*Mid)-cal(Mid);
            if(temp==m){
                res=Mid;break;
            }else if(temp<m)
                l=Mid+1;
            else r=Mid;
        }
       // printf("cal=%I64d\n",cal(2));
        if(res>=0)
            printf("%I64d\n",res);
        else printf("%I64d\n",l);
    }
    return 0;
}




