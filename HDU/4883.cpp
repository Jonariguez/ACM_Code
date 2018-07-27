/****************
*PID:hdu4883
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
    int v,t,left;
}s[maxn*2];

int cmp(const pp &x,const pp &y){
    if(x.t==y.t)
        return x.left<y.left;
    return x.t<y.t;
}

int main()
{
    int i,j,n,T,res;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            int v,h,m;
            scanf("%d %d:%d",&v,&h,&m);
            s[i*2].v=v;s[i*2].t=h*60+m;s[i*2].left=1;
            scanf("%d:%d",&h,&m);
            s[i*2+1].v=v;s[i*2+1].t=h*60+m;s[i*2+1].left=0;
        }
        sort(s,s+2*n,cmp);
        int res=0,cnt=0;
        for(i=0;i<2*n;i++){
            if(s[i].left)
                cnt+=s[i].v;
            else cnt-=s[i].v;
            res=max(res,cnt);
        }
        printf("%d\n",res);
    }
    return 0;
}

