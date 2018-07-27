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

const int maxn=100000+10;
const int MOD=1e9+7;

int dp[maxn][25];
int a[maxn];
int n;

void Init(){
    for(int i=0;i<n;i++)
        dp[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i+(1<<j)-1<n;i++)
            dp[i][j]=min(dp[i+(1<<(j-1))][j-1],dp[i][j-1]);
    }
}

int ask(int l,int r){
    int len=r-l+1;
    int k=0;
    while((1<<(k+1))<=len) k++;
    return min(dp[l][k],dp[r-(1<<k)+1][k]);
}

int solve(int l,int r){
    l--,r--;
    if(l==r) return a[l];
    int val=a[l];
    l++;
    while(l<=r){
        int lb=l,rb=r;
        while(lb<rb){
            int mid=(lb+rb)/2;
            if(ask(lb,mid)<=val)
                rb=mid;
            else if(ask(mid+1,rb)<=val) lb=mid+1;
            else return val;
        }
        l=lb+1;
        val=val%a[lb];
    }
    return val;
}

int main()
{
    int i,j,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        Init();
        scanf("%d",&m);
        while(m--){
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",solve(l,r));
        }
    }
    return 0;
}


