/****************
*PID:
*Auth:Jonariguez
*****************
http://blog.csdn.net/haut_ykc/article/details/77414829?locationNum=4&fps=1
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

int d[maxn],vis[maxn],flag[maxn];

struct node{
    int to,id;
};
vector<node> con[maxn];

int dfs(int u){
    int i,j,ans;
    vis[u]=1;ans=d[u];
    for(i=0;i<con[u].size();i++){
        node v=con[u][i];
        if(vis[v.to]) continue;
        if(dfs(v.to)){
            ans^=1;
            flag[v.id]=1;
        }
    }
    if(d[u]==-1)
        return 0;
    return ans;
}


int main()
{
    int i,j,n,m,e1=0,e=-1;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&d[i]);
        if(d[i]==-1) e=i;
        if(d[i]==1) e1++;
    }
    for(i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        node temp;
        temp.to=v;temp.id=i;
        con[u].push_back(temp);
        temp.to=u;temp.id=i;
        con[v].push_back(temp);
    }
    if(e<0 && e1%2){
        printf("-1\n");
        return 0;
    }
    int st=max(e,1);    //一定不能随便找点进行dfs
    dfs(st);
    int res=0;
    for(i=1;i<=m;i++)
        if(flag[i]) res++;
    printf("%d\n",res);
    for(i=1;i<=m;i++)
        if(flag[i]) printf("%d\n",i);
    return 0;
}



