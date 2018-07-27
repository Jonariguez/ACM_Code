/****************
*PID:
*Auth:Jonariguez
*****************
求出3个点的互达的路径和(两两距离之后/2)，然后减去最短的两点间的距离，
剩下的就是共同走的
最后注意要+1，因为d[]数组计算的是边数，答案是点数
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

int fa[maxn],anc[maxn][30],d[maxn];
vector<int> con[maxn];

void dfs(int u,int pa){
    fa[u]=pa;
    for(int i=0;i<con[u].size();i++){
        int v=con[u][i];
        if(v==pa) continue;
        d[v]=d[u]+1;
        dfs(v,u);
    }
}

void solve(int n){
    for(int i=1;i<=n;i++){
        anc[i][0]=fa[i];
        for(int j=1;(1<<j)<=n;j++) anc[i][j]=-1;
    }
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i<=n;i++){
            if(anc[i][j-1]!=-1){
                int a=anc[i][j-1];
                anc[i][j]=anc[a][j-1];
            }
        }
    }
}

int ask(int p,int q){
    int tmp,log,i;
    if(d[p]<d[q]) swap(p,q);
    for(log=1;(1<<log)<=d[p];log++);
    log--;
    int ans=-MOD;
    for(int i=log;i>=0;i--)
        if(d[p]-(1<<i)>=d[q])
            p=anc[p][i];
    if(p==q) return p;
    for(int i=log;i>=0;i--){
        if(anc[p][i]!=-1 && anc[p][i]!=anc[q][i]){
            p=anc[p][i];
            q=anc[q][i];
        }
    }
    return fa[q];
}

int main()
{
    int i,j,n,Q;
    scanf("%d%d",&n,&Q);
    for(i=2;i<=n;i++){
        int u;
        scanf("%d",&u);
        con[u].push_back(i);
        con[i].push_back(u);
    }
    d[1]=0;
    dfs(1,-1);
    solve(n);
    while(Q--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int lcp1=ask(a,b),lcp2=ask(a,c),lcp3=ask(b,c);
        int s1=d[a]+d[b]-2*d[lcp1];
        int s2=d[a]+d[c]-2*d[lcp2];
        int s3=d[c]+d[b]-2*d[lcp3];
        printf("%d\n",(s1+s2+s3)/2-min(min(s1,s2),s3)+1);
    }
    return 0;
}


