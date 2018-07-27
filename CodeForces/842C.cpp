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

vector<int> con[maxn];
int a[maxn],ans[maxn],v[maxn];

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

void dfs(int u,int pa,int d,int G){
    ans[u]=G;
    int i;
    for(i=1;i*i<a[u];i++){
        if(a[u]%i==0){
            v[i]++;
            if(v[i]>=d-1) ans[u]=max(ans[u],i);
            v[a[u]/i]++;
            if(v[a[u]/i]>=d-1) ans[u]=max(ans[u],a[u]/i);
        }
    }
    if(i*i==a[u]) ++v[i];
    if(v[i]>=d-1) ans[u]=max(ans[u],i);
    for(i=0;i<con[u].size();i++){
        int v=con[u][i];
        if(v==pa) continue;
        dfs(v,u,d+1,gcd(G,a[u]));
    }
    for(i=1;i*i<a[u];i++){
        if(a[u]%i==0){
            v[i]--;
            v[a[u]/i]--;
        }
    }
    if(i*i==a[u]) v[i]--;
}


int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        con[x].push_back(y);
        con[y].push_back(x);
    }
    dfs(1,0,1,0);
    for(i=1;i<=n;i++)
        printf("%d ",ans[i]);
    puts("");
    return 0;
}

