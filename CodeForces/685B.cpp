/****************
*PID:685b div1
*Auth:Jonariguez
*****************
考虑v最大的子树p，那么v子树的质心,一定是p子树的质心往v挪一段距离,暴力挪就好了。
复杂度正确的原因是考虑一段重链，那么这上面的质心其实只会从重链的底端挪到顶端，所以复杂度是对的。
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

const int maxn=300000+10;
const int MOD=1e9+7;
int cnt[maxn],res[maxn],par[maxn];
vector<int> con[maxn];

void dfs(int u){
    cnt[u]=1;
    for(int i=0;i<con[u].size();i++){
        int v=con[u][i];
        dfs(v);
        cnt[u]+=cnt[v];
    }
}

void dfs2(int u){
    int mx=0;
    for(int i=0;i<con[u].size();i++){
        int v=con[u][i];
        dfs2(v);
        if(cnt[v]>cnt[con[u][mx]])
            mx=i;   //找重孩子
    }
    if(con[u].size()){
        res[u]=res[con[u][mx]]; //先等于重孩子的质心
        while(true){
            if((cnt[u]-cnt[res[u]])*2<cnt[u]) break;    //直到在子树u中且在质心上面的节点数少于cnt[u]的一半即可。
            res[u]=par[res[u]]; //一直往上提
        }
    }else
        res[u]=u;
}


int main()
{
    int i,j,n,q;
    scanf("%d%d",&n,&q);
    for(i=2;i<=n;i++){
        scanf("%d",&par[i]);
        con[par[i]].push_back(i);
    }
    dfs(1);
    dfs2(1);
    while(q--){
        int x;
        sc(x);
        pfn(res[x]);
    }
    return 0;
}



