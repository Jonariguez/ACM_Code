/****************
*PID:613a
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define PI acos(-1.0)
#define eps 1e-10
typedef long long LL;
const int maxn=100000+10;

struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};

typedef Point Vertor;

Vertor operator + (Vertor a,Vertor b){
    return Vertor(a.x+b.x,a.y+b.y);
}

Vertor operator - (Vertor a,Vertor b){
    return Vertor(a.x-b.x,a.y-b.y);
}

Vertor operator * (Vertor a,double p){
    return Vertor(a.x*p,a.y*p);
}

Vertor operator / (Vertor a,double p){
    return Vertor(a.x/p,a.y/p);
}

bool operator < (const Point &a,const Point &b){
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}

int dcmp(double x){
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}

bool operator == (const Point &a,const Point &b){
    return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0;
}

double Dot(Vertor A,Vertor B){
    return A.x*B.x+A.y*B.y;
}

double Length(Vertor a){
    return sqrt(Dot(a,a));
}

double Angle(Vertor a,Vertor b){
    return acos(Dot(a,b)/Length(a)/Length(b));
}

double Cross(Vertor a,Vertor b){
    return a.x*b.y-a.y*b.x;
}

double DistanceToSegment(Point p,Point a,Point b){
    if(a==b) return Length(p-a);
    Vertor v1=b-a,v2=p-a,v3=p-b;
    if(dcmp(Dot(v1,v2))<0) return Length(v2);
    else if(dcmp(Dot(v1,v3))>0) return Length(v3);
    else return fabs(Cross(v1,v2))/Length(v1);
}

double DistanceToPoint(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

Point s[maxn];

int main()
{
    int i,j,n;
    Point P;
    while(scanf("%d%lf%lf",&n,&P.x,&P.y)!=EOF){
        double minx=10000000000000000,maxx=0.0;
        LL a,b;
        for(i=1;i<=n;i++)
            scanf("%lf%lf",&s[i].x,&s[i].y);
        for(i=1;i<n;i++){
            minx=min(minx,DistanceToSegment(P,s[i],s[i+1]));
            maxx=max(maxx,DistanceToPoint(P,s[i]));
        }
        minx=min(minx,DistanceToSegment(P,s[n],s[1]));
        maxx=max(maxx,DistanceToPoint(P,s[n]));
        printf("%.7f\n",PI*(maxx*maxx-minx*minx));
    }
    return 0;
}
