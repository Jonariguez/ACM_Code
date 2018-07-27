/****************
*PID:
*Auth:Jonariguez
*****************
dp[i][j]:选了i个数，当前质因子中2的个数为j，5的个数最多有多少
巧妙的状态设置
首先省了第一维n，然后根据类似背包的原理，采用倒叙枚举转移又
省去了第二维k，然后并不把2的个数和5的个数同时放到状态里，
把5的个数作为值来更新，最后同样能等到答案。
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

const int maxn=200+10;
const int MOD=1e9+7;
int maxm=12800;

int dp[202][12820];
int a[maxn],b[maxn],c[maxn];
int main()
{
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=0;i<=m;i++)
        for(j=0;j<=maxm;j++) dp[i][j]=-MOD;
    dp[0][0]=0;
    for(i=1;i<=n;++i){
        LL v;
        scanf("%I64d",&v);
        LL temp=v;
        while(temp%2==0){
            a[i]++;temp/=2;
        }
        temp=v;
        while(temp%5==0){
            b[i]++;temp/=5;
        }
        for(j=m;j>=1;j--){
            for(k=a[i];k<=maxm;k++){
                dp[j][k]=max(dp[j][k],dp[j-1][k-a[i]]+b[i]);
            }
        }
    }
    int res=0;
    for(i=0;i<=64*200;i++)
        res=max(res,min(i,dp[m][i]));
    printf("%d\n",res);
    return 0;
}


