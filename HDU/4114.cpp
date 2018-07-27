/****************
*PID:hdu4114
*Auth:Jonariguez
*****************
dp[visited][have][u]:当前已经访问了visited的景点，已经拿了能访问have景点的FastPass票，且当前在u点。
对于某个地点u，有两种选择：
①参观景点并拿FastPass票
②只去地方，不看景点，并拿票
即无论参不参观景点都要拿票是最优的。
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

const int maxn=55;
const int maxm=8;
const int INF=1e9;
int dp[1<<maxm][1<<maxm][maxn],n,m,k;
int mp[maxn][maxn],pos[maxm],T[maxm],FT[maxm];
int Have[maxn];

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(mp[i][k]!=INF && mp[k][j]!=INF && mp[i][j]>mp[i][k]+mp[k][j])
                    mp[i][j]=mp[i][k]+mp[k][j];
            }
        }
    }
}

int DP(){
    int i,j;
    for(i=0;i<(1<<k);i++){
        for(j=0;j<(1<<k);j++){
            for(int z=1;z<=n;z++) dp[i][j][z]=INF;
        }
    }
    dp[0][0][1]=0;
    int visited,have,u;
    for(visited=0;visited<(1<<k);visited++){
        for(have=0;have<(1<<k);have++){
            for(u=1;u<=n;u++){
                if(dp[visited][have][u]==INF) continue;
                for(i=0;i<k;i++){       //刻意地去参观每个景点。决策①
                    if((visited>>i)&1) continue;
                    int state=(visited|(1<<i)),cost=mp[u][pos[i]];
                    if((have>>i)&1) cost+=FT[i];
                    else cost+=T[i];
                    int &ans=dp[state][have|Have[pos[i]]][pos[i]];
                    ans=min(ans,dp[visited][have][u]+cost);
                }
                for(i=1;i<=n;i++)   //去其他n个地方，但不参加任何景点。决策②(别忘了+mp[u][i])
                    dp[visited][have|Have[i]][i]=min(dp[visited][have|Have[i]][i],dp[visited][have][u]+mp[u][i]);
            }
        }
    }
    int res=INF;
    for(i=0;i<(1<<k);i++)
        res=min(res,dp[(1<<k)-1][i][1]);    //因为最终还要回到1，所以这里是dp[][][1]
    return res;
}

int main()
{
    int i,j,cas,kcase=1;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d%d",&n,&m,&k);
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++) mp[i][j]=(i==j?0:INF);
        for(i=1;i<=m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            mp[a][b]=mp[b][a]=min(mp[a][b],c);
        }
        memset(Have,0,sizeof(Have));
        for(i=0;i<k;i++){
            int K;
            scanf("%d%d%d%d",&pos[i],&T[i],&FT[i],&K);
            while(K--){
                int x;
                sc(x);
                Have[x]|=(1<<i);
            }
        }
        floyd();
        printf("Case #%d: %d\n",kcase++,DP());
    }
    return 0;
}



