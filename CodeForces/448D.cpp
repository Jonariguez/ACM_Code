/****************
*PID:448d div2
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
LL n,m,k;

bool C(LL x){
    LL sum1=0,sum2=0;
    int f=0;
    for(LL i=1;i<=n;i++){
        if(i>x) break;
        sum1+=min(m,x/i);
        sum2+=min(m,x/i);
        if(x%i==0 && x/i<=m){
            f=1;sum2--;
        }
    }
  //  if(f==0) return false;
    return sum1<=k || (sum1>k && f && sum2<k) ;
}

int main()
{
    int i,j;
    while(scanf("%I64d%I64d%I64d",&n,&m,&k)!=EOF){
       // if(n==2 && m==2 && k==3){
       //     puts("2");continue;
       // }
        LL l=1,r=n*m,res=0;
        while(l<r){
            LL x=l+(r-l+1)/2;
            LL sum1=0,sum2=0;
            int f=0;
            for(LL i=1;i<=n;i++){
                if(i>x) break;
                sum1+=min(m,x/i);
                sum2+=min(m,x/i);
                if(x%i==0 && x/i<=m){
                    f=1;sum2--;
                }
            }
           // printf("x=%I64d sum1=%I64d sum2=%I64d f=%d\n",x,sum1,sum2,f);
            if(sum1>=k && sum2<k && f){
                l=x;break;//puts("??");
            }
            if(f==0){
                if(sum1<k) l=x+1;
                else r=x-1;
                continue;
            }
         //   puts("");
            if(sum1<k) l=x;
            else r=x-1;
         //   if(C(x))
         //       l=x;
         //   else r=x-1;
        }
        printf("%I64d\n",l);
    }
    return 0;
}
