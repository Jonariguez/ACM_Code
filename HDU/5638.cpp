/****************
*PID:hdu5638
*Auth:Jonariguez
*****************
http://blog.csdn.net/mymilkbottles/article/details/50826879
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
const LL mod=1e9+7;

int n,m,k,d[maxn],vis[maxn];
vector<int> con[maxn];

int main()
{
    int i,j,T;
    sc(T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        for(i=0;i<=n;i++)
            con[i].clear();
        memset(d,0,sizeof(d));
        for(i=1;i<=m;i++){
            int a,b;
            sc(a);sc(b);
            d[b]++;
            con[a].push_back(b);
        }
        priority_queue<int,vector<int>,greater<int> > que;
        for(i=1;i<=n;i++)
            que.push(i);
        memset(vis,0,sizeof(vis));
        LL res=0,cnt=1;
        while(!que.empty()){
            int u=que.top();que.pop();
            if(k<d[u]) continue;
            if(vis[u]) continue;
            vis[u]=1;
            k-=d[u];
            res+=cnt*u%mod;
            cnt++;
            res%=mod;
            for(i=0;i<con[u].size();i++){
                int v=con[u][i];
                if(vis[v]) continue;
                d[v]--;
                if(vis[v]==0){
                    que.push(v);
                }
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}



