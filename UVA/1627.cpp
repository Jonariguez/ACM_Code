/****************
*PID:uva1627
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
typedef pair<int,int> pii;
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100+10;
int mp[maxn][maxn],vis[maxn],col[maxn],diff[maxn];
vector<int> con[maxn],color[2],ver[maxn],res[2];
vector<pii> stage;
map<int,int> dp[maxn];
int idx;

bool dfs(int u,int pa,int c){
    vis[u]=1;
    color[c].push_back(u);
    ver[idx].push_back(u);
    for(int i=0;i<con[u].size();i++){
        int v=con[u][i];
        if(col[v]>=0){
            if(col[v]==col[u]) return false;
            else continue;
        }
        col[v]=1-c;
        if(!dfs(v,u,col[v]))
            return false;
    }
    return true;
}

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(mp,0,sizeof(mp));
        for(i=1;i<=n;i++){
            int x;
            while(scanf("%d",&x) && x)
                mp[i][x]=1;
            con[i].clear();
            dp[i].clear();
        }
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                if(mp[i][j]==0 || mp[j][i]==0){
                    con[i].push_back(j);
                    con[j].push_back(i);
                }
            }
        }
        memset(vis,0,sizeof(vis));
        memset(col,-1,sizeof(col));
        dp[0][0]=1;
        int yes=1,cnt=0;
        idx=0;
        for(i=1;i<=n;i++){
      //  puts("???");
            if(vis[i]==0){
                color[0].clear();color[1].clear();
                ver[++idx].clear();
                col[i]=0;
                if(!dfs(i,-1,0)){
                    yes=0;break;
                }
                int a=color[0].size(),b=color[1].size();
                int t=a-b;
                diff[idx]=t;
                for(j=-100;j<=100;j++){
                    if(dp[idx-1][j]<=0) continue;
                    dp[idx][j+t]=1;
                    dp[idx][j-t]=1;
                }
            }
        }
       // for(i=1;i<=n;i++)
       //     printf("%d ",col[i]);
       // for(i=1;i<=idx;i++)
       //     printf("diff=%d\n",diff[i]);
      //  puts("");
        if(yes==0)
            puts("No solution");
        else {
            int ans=0;
            for(i=0;i<=n;i++){
                if(dp[idx][i]){
                    ans=i;break;
                }
                if(dp[idx][-i]){
                    ans=-i;break;
                }
            }
            res[1].clear();res[0].clear();
            for(i=idx;i>=1;i--){
                int t=diff[i];
             //   printf("t=%d\n",t);
                if(dp[i-1][ans+t]>0){
                    ans+=t;     //±ðÍüÁËÐÞ¸Äans
                    for(j=0;j<ver[i].size();j++)
                        res[col[ver[i][j]]].push_back(ver[i][j]);
                }else if(dp[i-1][ans-t]>0){
                    ans-=t;
                    for(j=0;j<ver[i].size();j++)
                        res[col[ver[i][j]]^1].push_back(ver[i][j]);
                }
            }
          //  printf("ans=%d\n",ans);
            printf("%d ",res[0].size());
            for(i=0;i<res[0].size();i++)
                printf("%d%c",res[0][i]," \n"[i==res[0].size()-1]);
            printf("%d ",res[1].size());
            for(i=0;i<res[1].size();i++)
                printf("%d%c",res[1][i]," \n"[i==res[1].size()-1]);
        }
        if(T)
            puts("");
    }
    return 0;
}







