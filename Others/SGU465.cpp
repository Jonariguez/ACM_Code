/****************
*PID:sgu465
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

const int maxn=100+10;
const double INF=1000000000;
double dis[maxn][maxn],p[maxn];
int n,m,R;

struct edge{
    int a,b;
    double len;
}s[maxn*maxn];

void floyd(){
    int i,j,k;
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(dis[i][k]<INF && dis[k][j]<INF){
                    if(dis[i][j]>dis[i][k]+dis[k][j])
                        dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
}

double getans(int id,double L){
    int a=s[id].a,b=s[id].b;
    double sum=0;
    for(int i=1;i<=n;i++){
        sum+=p[i]*min(dis[a][i]+L,dis[b][i]+s[id].len-L);
    }
    return sum;
}

double solve(){
    double res=INF;
    int i,j;
    for(i=1;i<n;i++)
        if(dis[i][n]>=INF) return -1.0;
    double l,r,ll,rr,temp;
    for(i=1;i<=m;i++){
        if(s[i].len-2*R<0) continue;
        l=R;r=s[i].len-R;
        while(r-l>(1e-9)){
            ll=(2*l+r)/3;
            rr=(2*r+l)/3;
            if(getans(i,ll)>getans(i,rr))
                l=ll;
            else r=rr;
        }
        temp=getans(i,l);
        if(temp<res)
            res=temp;
    }
    if(res>=INF) return -1.0;
    return res;
}

int main()
{
    int i,j;
    while(scanf("%d%d%d",&n,&m,&R)!=EOF){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                dis[i][j]=INF;
            }
            dis[i][i]=0;
        }
        for(i=1;i<=n;i++){
            scanf("%lf",&p[i]);
            p[i]/=10000;
        }
        for(i=1;i<=m;i++){
            scanf("%d%d%lf",&s[i].a,&s[i].b,&s[i].len);
            int a=s[i].a,b=s[i].b;
            dis[a][b]=dis[b][a]=s[i].len;
        }
        floyd();
        double res=solve();
        if(n==1 && R==0)
            puts("0");
        else if(res<0)
            puts("-1");
        else printf("%.5f\n",res);
    }
    return 0;
}

