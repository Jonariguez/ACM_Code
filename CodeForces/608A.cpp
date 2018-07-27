/****************
*PID:608a div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000+10;
struct pp{
    int f,t;
}a[maxn];

int cmp(const pp &x,const pp &y){
    return x.f>y.f;
}


int main()
{
    int i,j,n,m,s;
    while(scanf("%d%d",&n,&s)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d%d",&a[i].f,&a[i].t);
        sort(a+1,a+n+1,cmp);
        int res=0,now=0,temp=s;
        for(i=1;i<=n;i++){
            res+=temp-a[i].f;
            now+=temp-a[i].f;
            if(now<a[i].t){
                res+=a[i].t-now;now=a[i].t;
            }
            temp=a[i].f;
        }
        if(a[n].f!=0)
            res+=temp;
        printf("%d\n",res);
    }
    return 0;
}
