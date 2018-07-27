/****************
*PID:5647
*Auth:Jonariguez
*****************
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
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=200000+10;
const LL MOD=1e9+7;
LL sizeOfSubtree[maxn];//表示以i为根节点的所有可能的子树大小之和
LL wayOfSubtree[maxn];//表示以i为根节点的子树方案
vector<int> con[maxn];

void add(int u,int v){
    con[u].push_back(v);
}

void dfs(int u,int pa){
    sizeOfSubtree[u]=1;
    wayOfSubtree[u]=1;
    for(int i=con[u].size()-1;i>=0;i--){
        int v=con[u][i];
        if(v==pa) continue;
        dfs(v,u);
        ///当前处理了u的前[0,i-1]子树，总共的子树大小为sizeOfSubtree[u],由于第i个子树u的出现，
        ///那么从v中任选一种子树方式再与前[0,i-1]形成子树，共可选wayOfSubtree[v]种，这样的话会
        ///使sizeOfSubtree[u]再算wayOfSubtree[v]，即再增加wayOfSubtree[v]倍。注意！！这里并没有
        ///同时把第i个子树v的size算进去，只是把之前[0,i-1]棵再加wayOfSubtree[v]倍。
        sizeOfSubtree[u]=sizeOfSubtree[u]+sizeOfSubtree[u]*wayOfSubtree[v];
        ///这里再算第i个子树v的size。该怎么算呢？现在已经知道子树v的所有可能子树的大小之和sizeOfSubtree[v]，
        ///那么它对sizeOfSubtree[u]的贡献是多少呢，即sizeOfSubtree[v]会被算几次呢？
        ///这样考虑，我们看当前以u为根的子树的方案数wayOfSubtree[u]，对于每一种方案，只需要把(u,v)连接，
        ///那么sizeOfSubtree[v]都要被累加一次，共累加wayOfSubtree[u]次。
        ///(即： 在以u为根的方案种取第1种方案  ---- 把以v为根的方案取一遍->共sizeOfSubtree[v]个节点
        ///      在以u为根的方案种取第2种方案  ---- 把以v为根的方案取一遍->共sizeOfSubtree[v]个节点
        /// .....在以u为根的方案种取第wayOfSubtree[u]种方案  ---- 把以v为根的方案取一遍->共sizeOfSubtree[v]个节点
        ///故共wayOfSubtree[u]倍。
        sizeOfSubtree[u]=sizeOfSubtree[u]+wayOfSubtree[u]*sizeOfSubtree[v];
        sizeOfSubtree[u]%=MOD;
        wayOfSubtree[u]=wayOfSubtree[u]*(wayOfSubtree[v]+1)%MOD;
    }
}

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++) con[i].clear();
        if(n==1){
            puts("1");continue;
        }
        for(i=2;i<=n;i++){
            int a;
            scanf("%d",&a);
            add(a,i);
        }
        dfs(1,-1);
        LL res=0;
        for(i=1;i<=n;i++){
            res+=sizeOfSubtree[i];
            res%=MOD;
        }
        printf("%I64d\n",res);
    }
    return 0;
}


