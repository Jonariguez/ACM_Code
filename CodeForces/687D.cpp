/****************
*PID:div1
*Auth:Jonariguez
*****************
题意：给一个图，n个点m条边，然后把[l,r]的某些边连接构成子图，
要求这个子图能够分成两个部分，每个部分的最大值的min就是答案。
按边从大到小排序
并查集合并时，第一次出现的联通的两个点（边i），那么就把这两个点作为一部分，
以前已经连接的点作为另一部分，这样答案就是边i的长度。
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

const int maxn=1000+10;
const int MOD=1e9+7;
int n;
int res[maxn];

struct edge{
    int a,b,c;
    int id;
}s[maxn*maxn];

int cmp(const edge &x,const edge &y){
    return x.c>y.c;
}

struct DSU{
    int par[maxn];
    void Init(){
        for(int i=0;i<=n;i++) par[i]=i;
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    bool Union(int u,int v){
        if((v=find(v))==(u=find(u))) return false;
        par[v]=u;
        return true;
    }
}Set;

int main()
{
    int i,j,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
        s[i].id=i;
    }
    sort(s+1,s+m+1,cmp);
    int l,r,cnt,v;
    while(q--){
        scanf("%d%d",&l,&r);
        Set.Init();
        int yes=0;
        for(i=1;i<=m;i++){
            if(s[i].id<l || s[i].id>r) continue;
            if(!Set.Union(s[i].a,s[i].b)){
                yes=1;
                printf("%d\n",s[i].c);
                break;
            }
        }
        if(!yes)
            puts("-1");
    }
    return 0;
}




