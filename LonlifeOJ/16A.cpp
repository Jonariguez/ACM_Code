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
const int MOD=19260817;

vector<int> vec[maxn];
int val[maxn],par[maxn],deep[maxn];

void dfs(int u,int pa,int D){
    deep[u]=D;
    for(int i=0;i<vec[u].size();i++){
        int v=vec[u][i];
        if(v==pa) continue;
        dfs(v,u,D+1);
        par[v]=u;
    }
}

int a[maxn];

int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&val[i]);
        vec[i].clear();
    }
    memset(par,0,sizeof(par));
    for(i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1,0,0);
    while(m--){
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1)
            val[x]=y;
        else {
            int X=x,Y=y,cnt=2,tot=0;
            while(X!=Y){
                if(deep[X]>=deep[Y])
                    X=par[X];
                else Y=par[Y];
                cnt++;//puts("???");
            }
            cnt--;
            while(x!=X){
                a[++tot]=val[x];
                x=par[x];
            }
            a[++tot]=val[x];
            int t=cnt;
            while(y!=Y){
                a[cnt--]=val[y];
                y=par[y];
            }
            int res=0;
            for(i=2;i<=t;i++){
                for(j=1;j<i;j++)
                    if(a[j]>a[i]) res++;
                res%=MOD;
            }
            printf("%d\n",res);
        }
    }
    return 0;
}


