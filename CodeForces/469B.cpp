/****************
*PID:469b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
int c[maxn],d[maxn],a[maxn],b[maxn];

int main()
{
    int i,j,n,res,q,p,l,r;
    while(scanf("%d%d%d%d",&p,&q,&l,&r)!=EOF){
        for(i=1;i<=p;i++) scanf("%d%d",&a[i],&b[i]);
        for(i=1;i<=q;i++) scanf("%d%d",&c[i],&d[i]);
        int t;res=0;
        for(t=l;t<=r;t++){
            int yes=0;
            for(i=1;i<=p && yes==0;i++){
                for(j=1;j<=q && yes==0;j++){
                    if(!(b[i]<c[j]+t || a[i]>d[j]+t))
                        yes=1;
                }
            }
            res+=yes;
        }
        printf("%d\n",res);
    }
    return 0;
}
