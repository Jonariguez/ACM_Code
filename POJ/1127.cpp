/****************
*PID:poj1127
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
#define eps 1e-9
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100+10;
int par[maxn];

void Init(){
    for(int i=0;i<maxn;i++)
        par[i]=i;
}

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

void Union(int u,int v){
    if((u=find(u))==(v=find(v)))
        return ;
    par[u]=v;
}

struct point{
    double x,y;
};

bool inter(point a,point b,point c,point d){
    if(min(a.x,b.x)>max(c.x,d.x) || min(a.y,b.y)>max(c.y,d.y) || min(c.x,d.x)>max(a.x,b.x) ||
       min(c.y,d.y)>max(a.y,b.y))
       return 0;
    double h,i,j,k;
    h=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
    i=(b.x-a.x)*(d.y-a.y)-(b.y-a.y)*(d.x-a.x);
    j=(d.x-c.x)*(a.y-c.y)-(d.y-c.y)*(a.x-c.x);
    k=(d.x-c.x)*(b.y-c.y)-(d.y-c.y)*(b.x-c.x);
    return h*i<=eps && j*k<=eps;
}

struct line{
    point p1,p2;
}s[maxn];

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        Init();
        for(i=1;i<=n;i++)
            scanf("%lf%lf%lf%lf",&s[i].p1.x,&s[i].p1.y,&s[i].p2.x,&s[i].p2.y);
        for(i=1;i<=n;i++){
            for(j=1;j<i;j++){
               // if(i==j) continue;
                if(inter(s[i].p1,s[i].p2,s[j].p1,s[j].p2))
                    Union(i,j);
            }
        }
        int a,b;
        while(scanf("%d%d",&a,&b)){
            if(a==0 && b==0) break;
            a=find(a);b=find(b);
            if(a==b)
                puts("CONNECTED");
            else puts("NOT CONNECTED");
        }
    }
    return 0;
}



