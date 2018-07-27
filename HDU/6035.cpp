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

int n,Size[maxn],c[maxn];
LL cnt[maxn],res;
vector<int> con[maxn];

void dfs(int u,int pa){
    Size[u]=1;
    LL temp=cnt[c[u]];
    for(int i=0;i<con[u].size();i++){
        int v=con[u][i];
        if(v==pa) continue;
        dfs(v,u);
        Size[u]+=Size[v];
    }
    LL temp2=cnt[c[u]];
    LL d=temp2-temp;
  //  if(n==Size[u])
  //      res+=Size[u]-d-1;
  //  else
    res+=1LL*(Size[u]-d-1)*(n-Size[u])+(Size[u]-d-1)+(n-Size[u]);
    cnt[c[u]]-=d;
    cnt[c[u]]+=Size[u];
}


int main()
{
    int i,j,kcase=1;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%d",&c[i]);
            con[i].clear();
        }
        for(i=1;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            con[a].push_back(b);
            con[b].push_back(a);
        }
        res=0;
        memset(cnt,0,sizeof(cnt));
        memset(Size,0,sizeof(Size));
        dfs(1,0);
        printf("Case #%d: %I64d\n",kcase++,res);
    }
    return 0;
}

