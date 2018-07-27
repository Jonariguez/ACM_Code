/****************
*PID:zoj3537
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

const int maxn=300+10;
const int INF=1e9;
int x[maxn],y[maxn];
int dp[maxn][maxn],P;

struct Point{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
    bool operator < (const Point &r) const {
        if(x==r.x)
            return y<r.y;
        return x<r.x;
    }
}p[maxn],ch[maxn];

typedef Point Vector;

Vector operator - (Point a,Point b){
    return Vector(a.x-b.x,a.y-b.y);
}

int Cross(Vector a,Vector b){
    return a.x*b.y-a.y*b.x;
}

int ConvexHull(Point *p,int n,Point *ch){
    sort(p,p+n);
    int m=0;
    for(int i=0;i<n;i++){
        while(m>1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;i--){
        while(m>k && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    if(n>1)
        m--;
    return m;
}

int cal(int i,int j){
    if(abs(i-j)<=1) return 0;   //×¢ÒâÕâÀï
    return (abs(ch[i].x+ch[j].x)*abs(ch[i].y+ch[j].y))%P;
}

int main()
{
    int i,j,k,n;
    while(scanf("%d%d",&n,&P)!=EOF){
        for(i=0;i<n;i++){
            scanf("%d%d",&x[i],&y[i]);
            p[i].x=x[i];p[i].y=y[i];
        }
        int m=ConvexHull(p,n,ch);
        if(m!=n){
            puts("I can't cut.");continue;
        }
        for(i=n;i>=1;i--) ch[i]=ch[i-1];
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                dp[i][j]=INF;
        for(i=1;i<n;i++)
            dp[i][i+1]=0;
        for(i=1;i<n-1;i++)
            dp[i][i+2]=0;
        for(i=n-2;i>=1;i--){
            for(j=i+2;j<=n;j++){
                for(k=i+1;k<j;k++)
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+cal(i,k)+cal(k,j));
            }
        }
        printf("%d\n",dp[1][n]);
    }
    return 0;
}



