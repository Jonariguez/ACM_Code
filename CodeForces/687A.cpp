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
int c[maxn];
vector<int> con[maxn],res1,res2;

bool dfs(int u,int C){
    if(C==1)
        res1.push_back(u);
    else res2.push_back(u);
    for(int i=0;i<con[u].size();i++){
        int v=con[u][i];
        if(c[v]){
            if(c[v]==c[u]) return false;
        }else {
            c[v]=3-c[u];
            if(!dfs(v,c[v])) return false;
        }
    }
    return true;
}

int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        int a,b;
        sc(a);sc(b);
        con[a].push_back(b);
        con[b].push_back(a);
    }
    int yes=1;
    for(i=1;i<=n;i++){
        if(!c[i]){
            c[i]=1;
            if(!dfs(i,1)){
                yes=0;break;
            }
        }
    }
    if(!yes)
        puts("-1");
    else {
        printf("%d\n",res1.size());
        for(i=0;i<res1.size();i++)
            printf("%d ",res1[i]);
        printf("\n%d\n",res2.size());
        for(i=0;i<res2.size();i++)
            printf("%d ",res2[i]);
        puts("");
    }
    return 0;
}

