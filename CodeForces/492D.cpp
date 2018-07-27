/****************
*PID:492d div2
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

const int maxn=100000+10;
LL n,x,y,a;

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    LL i,j,res;
    while(scanf("%I64d%I64d%I64d",&n,&x,&y)!=EOF){
        LL g=gcd(x,y);
        LL lcm=x/g*y;
        LL stepx=lcm/x,stepy=lcm/y;
        LL LCM=stepx/gcd(stepx,stepy)*stepy;
        for(i=1;i<=n;i++){
            scanf("%I64d",&a);
            if(x==y){
                printf("Both\n");continue;
            }
           // a%=(x+y);
          /*  if(a==0){
                if(x>y)
                    printf("Vanya\n");
                else printf("Vova\n");
                continue;
            }*/
          //  if(a==0 || a==x+y-1){
          //      printf("Both\n");
         //       continue;
         //   }
            LL l=0,r=2000000000000000000;
            while(l<r-1){
                LL m=(l+r)/2;
                if(m/stepx+m/stepy<a)
                    l=m;
                else r=m;
            }
          //  printf("r=%I64d\n",r);
          /*  if((r+1)%(x+y)==0)
                printf("Both\n");
            else if(r%(x+y)==0){
                if(x>y) printf("Vanya\n");
                else printf("Vova\n");*/
            if(r%stepx==0 && r%stepy==0)
                printf("Both\n");
            else if(r%stepy==0)
                printf("Vova\n");
            else if(r%stepx==0)
                printf("Vanya\n");
            else if(r%stepx<r%stepy)
                printf("Vanya\n");
            else printf("Vova\n");
        }
    }
    return 0;
}
