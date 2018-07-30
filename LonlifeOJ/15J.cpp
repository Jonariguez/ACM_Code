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

const int maxn=200000+10;
const int MOD=1e9+7;

struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};

typedef Point Vector;

Vector operator + (Vector A,Vector B){
    return Vector(A.x+B.x,A.y+B.y);
}

Vector operator - (Vector A,Vector B){
    return Vector(A.x-B.x,A.y-B.y);
}

Vector operator * (Vector A,double p){
    return Vector(A.x*p,A.y*p);
}

Vector operator / (Vector A,double p){
    return Vector(A.x/p,A.y/p);
}

bool operator < (const Point& a,const Point& b){
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}

const double eps=1e-10;

int dcmp(double x){
    if(fabs(x)<eps) return 0;
    else return x<0?-1:1;
}

bool operator == (const Point& a,const Point& b){
    return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0;
}

double Dot(Vector A,Vector B){ return A.x*B.x+A.y*B.y;}
double Length(Vector A){ return sqrt(Dot(A,A));}
double Angle(Vector A,Vector B){
    return acos(Dot(A,B)/Length(A)/Length(B));
}

double Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
Vector Rotate(Vector a,double rad){
    return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}

Point Get(Point P,Vector v,Point Q,Vector w){
    Vector u=P-Q;
    double t=Cross(w,u)/Cross(v,w);
    return P+v*t;
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        int i1,i2,i3,i4;
        scanf("%d%d%d%d",&i1,&i2,&i3,&i4);
        double A=1.0*i1/180*PI,B=1.0*i2/180*PI,C=1.0*i3/180*PI,D=1.0*i4/180*PI;
        double ding=PI-A-B-C-D;
        Vector z=Vector(0,-100);
        Vector b=Rotate(z,ding/2);
        Vector a=Rotate(z,2*PI-ding/2);
        Point X;
        X.x=a.x;X.y=a.y;
        Point Y;
        Y.x=b.x;Y.y=b.y;
        Vector c;
        c.x=100000;c.y=0;
        Vector d;
        d.x=-100000;d.y=0;
        Point O;
        O.x=O.y=0.0;
        c=Rotate(c,B);d=Rotate(d,2*PI-D);
        Point q=Get(O,b,X,c);
        Point p=Get(O,a,Y,d);
        Vector aa;
        aa.x=X.x-q.x;aa.y=X.y-q.y;
        Vector bb;
        bb.x=p.x-q.x;bb.y=p.y-q.y;
        printf("%.2f\n",(Angle(bb,aa)/PI*180));
    }
    return 0;
}

