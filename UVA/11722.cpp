/****************
*PID:uva11722
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

const int maxn=100000+10;

double s1,s2,t2,t1,width,height;

double cal(double w){
    double ly=t1+w,ry=t2+w;
    double tx=s2-w,bx=s1-w;
    bool on_left= s1<=ly && ly<=s2;
    bool on_right= s1<=ry && ry<=s2;
    bool on_top= t1<=tx && tx<=t2;
    bool on_buttom= t1<=bx && bx<=t2;
    if(on_left && on_right)
        return (s2-ry+s2-ly)*width*0.5;
    if(on_left && on_top)
        return (tx-t1)*(s2-ly)*0.5;
    if(on_top && on_buttom)
        return (bx-t1+tx-t1)*height*0.5;
    if(on_right && on_buttom)
        return height*width-(ry-s1)*(t2-bx)*0.5;
    return ly<=s1?width*height:0;
}

int main()
{
    int i,j,T,kcase=1;
    sc(T);
    while(T--){
        double w;
        scanf("%lf%lf%lf%lf%lf",&t1,&t2,&s1,&s2,&w);
        printf("Case #%d: ",kcase++);
        width=t2-t1;
        height=s2-s1;
        double tot=width*height;
        double ans1=cal(w);
        double ans2=cal(-w);
        printf("%.8f\n",(ans2-ans1)/tot);
    }
    return 0;
}



