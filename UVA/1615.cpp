/****************
*PID:uva1615
*Auth:Jonariguez
*****************
该题一定要用标准输入!=EOF,不然WA
有y[maxn]数组，也不能用C++11，不然RE
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define eps 1e-6

const int maxn=100000+10;
double x[maxn],y[maxn],D;

struct segment{
    double l,r;
}s[maxn*2];

int cmp(const segment &x,const segment &y){
    if(fabs(x.r-y.r)<eps)
        return x.l<y.l;
    return x.r<y.r;
}

double dis(double L1,double L2){
    return sqrt(L1*L1-L2*L2);
}

int main()
{
    int i,n;
    double L;
    while(scanf("%lf%lf",&L,&D)==2){
        scanf("%d",&n);
        double delta;
        for(i=0;i<n;i++){
            scanf("%lf %lf",&x[i],&y[i]);
            delta=dis(D,fabs(y[i]));
            s[i].l=max(0.0,x[i]-delta);
            s[i].r=min(L,x[i]+delta);
        }
        sort(s,s+n,cmp);
        int res=1;
        double v=s[0].r;
        for(i=0;i<n;i++){
            if(v<s[i].l){
                res++;
                v=s[i].r;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}

