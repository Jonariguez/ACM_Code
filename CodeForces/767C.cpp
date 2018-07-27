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

const int maxn=1000000+10;
const int MOD=1e9+7;

vector<int> con[maxn];

int v[maxn],sum[maxn],sum1,r;
vector<int> res;

void dfs(int u){
    if(res.size()>=2) return ;
    sum[u]=v[u];
    for(int i=0;i<con[u].size();i++){
        int x=con[u][i];
        dfs(x);
        sum[u]+=sum[x];
    }
    if(r!=u && sum[u]==sum1/3){
        res.push_back(u);sum[u]=0;
    }
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            con[i].clear();
        int a,t;
        r=-1;
        sum1=0;
        for(i=1;i<=n;i++){
            scanf("%d%d",&a,&v[i]);
            sum1+=v[i];
            if(a==0){
                r=i;continue;
            }
            con[a].push_back(i);
        }
        if(sum1%3){
            printf("-1\n");continue;
        }
        res.clear();
        dfs(r);
        if(res.size()<2){
            puts("-1");continue;
        }
        printf("%d %d\n",res[0],res[1]);
    }
    return 0;
}

