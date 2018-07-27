/****************
*PID:hdu5701
*Auth:Jonariguez
*****************
枚举每个数作为中位数i，然后先向左计算[1,i-1]的每个位置j，
如果a[j]>a[i] cnt++;
如果a[j]<a[i] cnt++;
然后vis[cnt]++;
然后向右枚举位置j:[i+1,n]，对于计算的cnt，去找在[1,i-1]中
有几个-cnt即可。
注意，cnt可能为负，所以hash时将cnt统一+n
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
typedef long long Ll;
Ll quick_pow(Ll a,LL b,LL MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;
const int MOD=1e9+7;
int a[maxn];
int res[maxn];
int vis[maxn];

int main()
{
    int i,j,k,n,m,T;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            res[i]=1;
        }
        int s,t,cnt=0;
        for(i=1;i<=n;i++){
            cnt=0;
            k=i+1;
            for(j=0;j<=2*n;j++)
                vis[j]=0;
            for(j=i-1;j>=1;j--){
                if(a[j]>a[i]) cnt++;
                else cnt--;
                vis[cnt+n]++;
            }
            cnt=0;
            for(j=i+1;j<=n;j++){
                if(a[j]>a[i]) cnt++;
                else cnt--;
                res[i]+=vis[n-cnt];
                if(cnt==0) res[i]++;
            }
            res[i]+=vis[n];
        }
        for(i=1;i<n;i++)
            printf("%d ",res[i]);
        printf("%d\n",res[n]);
    }
    return 0;
}
