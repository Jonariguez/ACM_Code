/****************
*PID:cf580B
*Auth:Jonariguez
*****************
按每个好友的money排序后尺取
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
struct pp{
    int m,s;
}a[maxn];

int cmp(const pp &x,const pp &y){
    if(x.m==y.m)
        return x.s>y.s;
    return x.m<y.m;
}

int main()
{
    int i,j,n,d;
    while(scanf("%d%d",&n,&d)!=EOF){
        for(i=0;i<n;i++)
            scanf("%d%d",&a[i].m,&a[i].s);
        sort(a,a+n,cmp);
        int s=0,t=0;
        __int64 res=0,sum=0;
        while(t<n){
            while(t<n && a[t].m-a[s].m<d){
                sum+=a[t].s;
                t++;
            }
            res=max(res,sum);
            sum-=a[s++].s;
        }
        printf("%I64d\n",res);
    }
    return 0;
}
