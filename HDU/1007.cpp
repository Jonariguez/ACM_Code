#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
const double INF=1e20;

struct Point{
    double x,y;
}s[maxn];

double dis(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int cmpxy(const Point &a,const Point &b){
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

int cmpy(const Point &a,const Point &b){
    return a.y<b.y;
}

Point temp[maxn];

double Closest_Pair(int l,int r){
    if(l+1==r)
        return dis(s[l],s[r]);
    if(l==r) return INF;
    int m=(l+r)/2;
    double d1=Closest_Pair(l,m);
    double d2=Closest_Pair(m+1,r);
    double d=min(d1,d2);
    int tot=0;
    for(int i=l;i<=r;i++){
        if(fabs(s[m].x-s[i].x)<=d)
            temp[tot++]=s[i];
    }
    sort(temp,temp+tot,cmpy);
    for(int i=0;i<tot-1;i++)
        for(int j=i+1;j<tot && fabs(temp[j].y-temp[i].y)<=d;j++)
            d=min(d,dis(temp[i],temp[j]));
    return d;
}

int main()
{
    int i,j,k,n;
    while(scanf("%d",&n),n){
        for(i=1;i<=n;i++)
            scanf("%lf%lf",&s[i].x,&s[i].y);
        sort(s+1,s+n+1,cmpxy);
        double res=Closest_Pair(1,n);
        printf("%.2f\n",res/2);
    }
    return 0;
}
