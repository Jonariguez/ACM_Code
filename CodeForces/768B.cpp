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

map<LL,int> dp;

LL cal(LL n){
    if(n==1) return 1;
    return cal(n/2)*2+1;
}

int dfs(LL n,LL l,LL r){    //ÏòÓÒµÝ¹é±ðÍüÁË-mid
    //printf("n=%I64d l=%I64d r=%I64d\n",n,l,r);
    if(l>r) return 0;
    if(n==0) return 0;
    if(n==1) return 1;
    LL m=cal(n);
    LL mid=m/2+1;
    if(l==mid && r==mid)
        return (n&1?1:0);
    if(r<mid)
        return dfs(n/2,l,r);
    if(l<mid && r==mid)
        return dfs(n/2,l,mid-1)+(n&1?1:0);
    if(l==mid && r>mid)
        return dfs(n/2,1,r-mid)+(n&1?1:0);
    if(l>mid)
        return dfs(n/2,l-mid,r-mid);
    if(l<mid && r>mid){
        return dfs(n/2,l,mid-1)+dfs(n/2,1,r-mid)+(n&1?1:0);
    }
}

int main()
{
    int i,j;
    LL n,l,r;
    while(scanf("%I64d%I64d%I64d",&n,&l,&r)!=EOF){
        printf("%d\n",dfs(n,l,r));
    }
    return 0;
}


