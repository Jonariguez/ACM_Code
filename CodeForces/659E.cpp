/****************
*PID:659e div2
*Auth:Jonariguez
*****************
对于一个联通分量，如果边数少于顶点数则一定有一个separate的city
如果边数>=顶点数则不会。
因为从形成环的某点指出去，形成一条链，再由多余的边再指回来即可
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

const int maxn=100000+10;
int vis[maxn];
vector<int> con[maxn],ans;

void Init(int n){
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n;i++)
        con[i].clear();
    ans.clear();
}

void add(int u,int v){
    con[u].push_back(v);
}

void bfs(int s){
    queue<int> que;
    vis[s]=1;
    que.push(s);
    while(!que.empty()){
        int u=que.front();que.pop();
        ans.push_back(u);
        for(int i=0;i<con[u].size();i++){
            int v=con[u][i];
            if(vis[v]) continue;
            que.push(v);
            vis[v]=1;
        }
    }
}

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        Init(n);
        for(i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);add(b,a);
        }
        int res=0;
        for(i=1;i<=n;i++){
            if(vis[i]==0){
                ans.clear();
                bfs(i);
                int sum=0;
                for(j=0;j<ans.size();j++)
                    sum+=con[ans[j]].size();
                sum/=2;
                if(sum<ans.size())
                    res++;
            }
        }
        pfn(res);
    }
    return 0;
}




