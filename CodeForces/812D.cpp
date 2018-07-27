/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(j,n) for(j=0;j<=(n);j++)
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
#define PB push_back
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
typedef long long Ll;
Ll Pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=200000+10;
const int MOD=1e9+7;

int mp[maxn],vis[maxn],in[maxn],out[maxn],dfs_clock;
vector<int> con[maxn];

void dfs(int u,int b){
    in[u]=++dfs_clock;
    for(int i=0;i<con[u].size();i++){
        int v=con[u][i];
        dfs(v,b);
    }
    out[u]=dfs_clock;
}



int main()
{
    int i,j,n,m,k,q;
    scanf("%d%d%d%d",&n,&m,&k,&q);
    memset(mp,0,sizeof(mp));
    for(i=1;i<=k;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(mp[b]){
            con[mp[b]].push_back(a);    //上一个玩b的人mp[b]玩完之后会给a
        }
        mp[b]=a;
    }
    dfs_clock=0;
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++){
        if(in[i]) continue;
        dfs(i,i);
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        y=mp[y];        //上面连边是：玩完之后给下一个人，现在找到最后一个玩y玩具的人b=mp[y]，给b要y玩具
                //即，上面说x玩完某个玩具(设为w)给下一个人，现在x说我还不能给，因为我现在还想玩y玩具，所以
                //之前的w玩具不能给出去，所以说因为把w给出去而导致能顺利玩到玩具的小孩们(这些小孩里最后一个是b)
                //现在都变成没有玩到w玩具，那他们就都变成等了，如果这个时候说：x非但没有把w给到b，而且还给b要玩具
                //y，那么这必然就开始哭了，而且从x一直到b这些中间的小孩也都会哭。
        if(in[x]<=in[y] && out[x]>=in[y])
            printf("%d\n",out[x]-in[x]+1);
        else printf("0\n");
    }
    return 0;
}




