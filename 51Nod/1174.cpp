/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(i,n) for(i=0;j<=(n);i++)
#define re(i,n) for(i=1;i<(n);i++)
#define re0(i,n) for(i=0;i<(n);i++)
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
#define PB push_back
#define X first
#define Y second
#define PI acos(-1.0)
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
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
typedef long long Ll;
Ll Pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=10000+10;
const int MOD=1e9+7;

int a[maxn],dp[maxn][30];

int main()
{
    int i,j,n,Q;
    sc(n);
    for(i=0;i<n;i++) sc(dp[i][0]);
    for(j=1;(1<<j)<n;j++){
        for(i=0;i+(1<<j)-1<n;i++){
            dp[i][j]=max(dp[i][j-1],dp[i+(1<<j-1)][j-1]);
        }
    }
    sc(Q);
    while(Q--){
        int l,r;
        sc(l);sc(r);
        int k=log2(r-l+1);
        printf("%d\n",max(dp[l][k],dp[r-(1<<k)+1][k]));
    }
    return 0;
}


