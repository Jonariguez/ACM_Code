/****************
*PID:bzoj1004
*Auth:Jonariguez
*****************
Burnside定理+dp+逆元
由Burnside定理可知，应该去枚举每一个置换，计算在该置换下，
有多少着色是不变着色，计算方法为：找出该置换里的圈，并存下
每个圈里点的个数，设为a1,a2,..,ak,然后做个三维的dp，
dp[i][j][k]:蓝色i张，红色j张，绿色k张的方案数，结果为dp[Sb][Sr][Sg]
求出每一个置换的不变着色之后求和sum。
sum/(m+1) %P即为答案。
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

const int maxn=100+10;
const int MOD=1e9+7;

bool vis[maxn];
int c[maxn][maxn];
int dp[maxn][maxn][maxn];
vector<int> vec;

int Pow(int a,int b,int mod){
    int res=1;
    while(b){
        if(b&1)
            res=(res*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return res;
}

int main()
{
    int i,j,n,Sb,Sr,Sg,m,P;
    scanf("%d%d%d%d%d",&Sr,&Sb,&Sg,&m,&P);
    n=Sr+Sb+Sg;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++)
            scanf("%d",&c[i][j]);
    }
    m++;
    for(i=1;i<=n;i++) c[m][i]=i;
    int b,r,g;
    LL res=0;
    for(i=1;i<=m;i++){
        memset(vis,0,sizeof(vis));
        vec.clear();
        for(j=1;j<=n;j++){
            if(vis[j]) continue;
            int cur=j,cnt=1;
            vis[j]=1;
            cur=c[i][cur];
            while(vis[cur]==0){
                vis[cur]=1;
                cur=c[i][cur];
                cnt++;
            }
            vec.push_back(cnt);
        }
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=1;
        for(j=0;j<vec.size();j++){
            int v=vec[j];
            for(b=Sb;b>=0;b--){
                for(r=Sr;r>=0;r--){
                    for(g=Sg;g>=0;g--){
                        if(b>=v)
                            dp[b][r][g]=(dp[b][r][g]+dp[b-v][r][g])%P;
                        if(r>=v)
                            dp[b][r][g]=(dp[b][r][g]+dp[b][r-v][g])%P;
                        if(g>=v)
                            dp[b][r][g]=(dp[b][r][g]+dp[b][r][g-v])%P;
                    }
                }
            }
        }
        /*
            for(b=0;b<=Sb;b++){
                for(r=0;r<=Sr;r++){
                    for(g=0;g<=Sg;g++){
                        if(dp[b][r][g]){
                            if(v+b<=Sb)
                                dp[v+b][r][g]=(dp[v+b][r][g]+dp[b][r][g])%P;
                            if(v+r<=Sr)
                                dp[b][v+r][g]=(dp[b][v+r][g]+dp[b][r][g])%P;
                            if(v+g<=Sg)
                                dp[b][r][v+g]=(dp[b][r][v+g]+dp[b][r][g])%P;
                        }
                    }
                }
            }
        }*/
        res=(res+dp[Sb][Sr][Sg])%P;
    }
    int inv=Pow(m,P-2,P);
    res*=inv;
    res%=P;
    printf("%lld\n",res);
    return 0;
}




