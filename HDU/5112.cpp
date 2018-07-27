/****************
*PID:hdu5112
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10000+10;
struct pp{
    int x,t;
}s[maxn];

int cmp(const pp &a,const pp &b){
    return a.t<b.t;
}

int main()
{
    int i,j,n,T,kcase=1;
    double res;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d",&s[i].t,&s[i].x);
        sort(s,s+n,cmp);
        res=-1.0;
        for(i=0;i<n-1;i++)
            res=max(res,fabs(s[i].x-s[i+1].x)/(s[i+1].t-s[i].t));
        printf("Case #%d: %.2f\n",kcase++,res);
    }
    return 0;
}
