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
vector<int> con[maxn];

double dp[maxn];
int cnt[maxn],cur;

void dfs(int u){
    cnt[u]=1;
    for(int i=0;i<con[u].size();i++){
        int v=con[u][i];
        dfs(v);
        cnt[u]+=cnt[v];
    }
}

void solve(int u){
    cur++;
    int c=con[u].size();
    for(int i=0;i<c;i++){
        int v=con[u][i];
        int sum=cnt[u]-1-cnt[v];
        dp[v]=dp[u]+sum*0.5+1;
        /*
        dp[v]=(dp[u]+1.0)/c;
        for(int j=1;j<c;j++){
            dp[v]+=(sum+dp[u]+1.0)*j/(c-1)/c;
        }*/
        solve(v);
    }
}

int main()
{
    int i,j,n;
    sc(n);
    for(i=2;i<=n;i++){
        int x;
        sc(x);
        con[x].push_back(i);
    }
    dfs(1);
    dp[1]=1.0;
    solve(1);
    for(i=1;i<=n;i++)
        printf("%.8f ",dp[i]);
    return 0;
}



