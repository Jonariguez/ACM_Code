/****************
*PID:hdu5533
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
#define eps 1e-8
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100+10;
int d[maxn];
struct Point{
    int x,y;
}s[maxn],ch[maxn];

int cmp(const Point &a,const Point &b){
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

int Cross(Point a,Point b){
    return a.x*b.y-a.y*b.x;
}

int Dot(Point a,Point b){
    return a.x*b.x+a.y*b.y;
}

double Length(Point a){
    return sqrt((double)Dot(a,a));
}

double Angle(Point a,Point b){
    return acos((double)Dot(a,b)*100.0/Length(a)/Length(b));
}

Point operator - (Point a,Point b){
    Point c;
    c.x=a.x-b.x;
    c.y=a.y-b.y;
    return c;
}

int ConvexHull(Point* p,int n,Point* ch){
    int m=0,i;
    for(i=0;i<n;i++){
        while(m>1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(i=n-2;i>=0;i--){
        while(m>k && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    if(n>1) m--;
    return m;
}

int dis(Point a,Point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

double ang[maxn];

int main()
{
    int i,j,n,m,T;
    sc(T);
    while(T--){
        sc(n);
        for(i=0;i<n;i++){
            scanf("%d%d",&s[i].x,&s[i].y);
        }
        sort(s,s+n,cmp);
        m=ConvexHull(s,n,ch);
        if(m!=n){
            puts("NO");continue;
        }
        int tot=0;
        for(i=0;i<n;i++)
            d[tot++]=dis(ch[i],ch[(i+1)%n]);
        sort(d,d+tot);
        if(d[0]!=d[tot-1]){
            puts("NO");continue;
        }
        tot=0;
        ang[tot++]=Angle(ch[n-1]-ch[0],ch[1]-ch[0]);
        for(i=1;i<n;i++)
            ang[tot++]=Angle(ch[i-1]-ch[i],ch[(i+1)%n]-ch[i]);
        for(i=1;i<tot;i++)
            if(fabs(ang[i]-ang[i-1])>eps)
                break;
        if(i<tot)
            puts("NO");
        else puts("YES");
    }
    return 0;
}



