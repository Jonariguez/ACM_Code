#pragma comment(linker, "/STACK:102400000,102400000")
#include <stdio.h>
#include <cstring>
#include <cassert>
#include <vector>
#include <cstdlib>
typedef long long LL;
#include <algorithm>
using namespace std;
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;
const int MOD=1e9+7;

int c[maxn],T[maxn],cnt[maxn],res[maxn];
bool vis[maxn];
vector<int> vec[maxn];

void dfs(int u){
    if(vec[u].size()==0){
        if(T[c[u]]<=1){
            res[u]=1;
            vis[c[u]]=1;
        }
        cnt[c[u]]++;
        return ;
    }
    for(int i=0;i<vec[u].size();i++){
        int v=vec[u][i];
        dfs(v);
        res[u]+=res[v];
    }
    cnt[c[u]]++;
    if(vis[c[u]]==0 && cnt[c[u]]>=T[c[u]]){
        res[u]++;vis[c[u]]=1;
    }
}

int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        vec[i].clear();
    for(i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        vec[x].push_back(i);
    }
    for(i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&T[i]);
    memset(vis,0,sizeof(vis));
    memset(res,0,sizeof(res));
    dfs(1);
    LL ans=0;
    for(i=1;i<=n;i++)
        ans+=res[i];
    printf("%lld\n",ans);
    return 0;
}

