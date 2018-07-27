/****************
*PID:uva1312
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
const int maxcoord=10000+10;
int x[maxn],y[maxn];

int main()
{
    int i,j,n,m,w,h,k,l,ll,p,q,bl,bp,bq,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&w,&h);
        for(i=1;i<=n;i++)
            scanf("%d%d",&x[i],&y[i]);
        bl=0;
        for(i=0;i<=n;i++){
            if(i==0) p=0;
            else p=x[i];
            for(j=0;j<=n;j++){
                if(j==0) q=0;
                else q=y[j];
                l=min(w-p,h-q);//
                for(k=1;k<=n;k++){
                    if(x[k]>p && y[k]>q){
                        ll=max(x[k]-p,y[k]-q);//
                        if(ll<l) l=ll;//
                    }
                }
                if(l>bl){
                    bl=l;bp=p;bq=q;
                }
            }
        }
        printf("%d %d %d\n",bp,bq,bl);
        if(T) printf("\n");
    }
    return 0;
}
