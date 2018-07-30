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
int a[maxn],b[maxn];
int stmax[maxn][20],stmin[maxn][20];

void Init(int n)
{
    int i,j;
    for (i = 0 ; i < n ;i++){
        stmax[i][0] = a[i];
        stmin[i][0] = a[i];
    }
    for(int i = n-1 ; i>= 0 ;i--)
    {
        for (int j =1 ; i+(1 << j)-1 < n;j++)
        {
            stmax[i][j] = max(stmax[i][j-1],stmax[i+(1 << j-1)][j-1]);
            stmin[i][j] = min(stmin[i][j-1],stmin[i+(1 << j-1)][j-1]);
        }
    }
}

LL ask(int l,int r)
{
    int k = (int)floor(log2(r-l+1));
    return 1LL*max(stmax[l][k],stmax[r-(1<<k)+1][k])*min(stmin[l][k],stmin[r-(1<<k)+1][k]);
}

int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    Init(n);
    for(i=0;i<n;i++){
        int l=i-b[i]+1,r=i;
        if(l>r) swap(l,r);
        printf("%lld\n",ask(l,r));
    }
    return 0;
}
