/****************
*PID:poj3666
*Auth:Jonariguez
*****************
dp[i][j]:前i个数，第i个数在数列中是第j小的元素的mincost

http://blog.csdn.net/tongyongzh/article/details/6645100
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

const int maxn=2000+10;
int dp[2][maxn],b[maxn];
vector<int> c;

int solve(int n){
    int temp,i,j;
    memset(dp,0,sizeof(dp));
    int *pre=dp[0],*now=dp[1];
    for(i=1;i<=n;i++){
        temp=2e9;
        for(j=1;j<=n;j++){
            temp=min(temp,pre[j]);
            now[j]=temp+abs(c[i]-b[j]);
        }
        swap(pre,now);
    }
    temp=pre[1];
    for(i=2;i<=n;i++)
        temp=min(temp,pre[i]);
    return temp;
}


int main()
{
    int i,j,n;
    sc(n);
    c.push_back(0);
    for(i=1;i<=n;i++){
        int x;
        sc(x);
        c.push_back(x);
        b[i]=x;
    }
    c.push_back(0);
    sort(b+1,b+n+1);
    int res=solve(n);
    reverse(c.begin(),c.end());
    res=min(res,solve(n));
    pfn(res);
    return 0;
}


