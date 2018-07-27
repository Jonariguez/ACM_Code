/****************
*PID:
*Auth:Jonariguez
*****************
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

const int maxn=1000+10;
const int MOD=1e9+7;
const double INF = 1e30;

LL sum[maxn];
double dp[maxn][maxn][2],v;
int vis[maxn][maxn][2],kcase=0,n;

struct node{
    double x,c,d;
}s[maxn];

int cmp(const node &a,const node &b){
    return a.x<b.x;
}

double cost(double x1,double x2,int i,int j){
    double ti=fabs(x1-x2)/v;
    if(i>j) return ti*sum[n];
    return (sum[i-1]+sum[n]-sum[j])*ti;
}

double DP(int i,int j,int p){
    if(i==1 && j==n) return 0;
    double &ans=dp[i][j][p];
    if(vis[i][j][p]==kcase) return ans;
    vis[i][j][p]=kcase;

    ans=INF;
    double x=(p==0?s[i].x:s[j].x);
    if(i>1)
        ans=min(ans,DP(i-1,j,0)+cost(x,s[i-1].x,i,j));
    if(j<n)
        ans=min(ans,DP(i,j+1,1)+cost(x,s[j+1].x,i,j));
    return ans;
}


int main()
{
    int i,j;
    double x;
    memset(vis,0,sizeof(vis));
    while(scanf("%d%lf%lf",&n,&v,&x)!=EOF){
        if(n==0) break;
        kcase++;
        double sumc=0;
        for(i=1;i<=n;i++){
            scanf("%lf%lf%lf",&s[i].x,&s[i].c,&s[i].d);
            sumc+=s[i].c;
        }
        sort(s+1,s+n+1,cmp);
        sum[0]=0;
        for(i=1;i<=n;i++)
            sum[i]=sum[i-1]+s[i].d;

        s[0].x=-INF;
        s[n+1].x=INF;
        double ans=INF;
        for(i=1;i<=n+1;i++){
            if(x>s[i-1].x && x<s[i].x){
                if(i>1)
                    ans=min(ans,DP(i-1,i-1,0)+cost(x,s[i-1].x,1,0));
                if(i<=n)
                    ans=min(ans,DP(i,i,0)+cost(x,s[i].x,1,0));
                break;
            }
        }
        printf("%.0lf\n",floor(ans+sumc));
    }
    return 0;
}




