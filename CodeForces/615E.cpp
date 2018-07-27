/****************
*PID:615e div2
*Auth:Jonariguez
*****************
第i层要走6*i个六边形。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

LL n;
LL dx[6]={-1,-2,-1,1,2,1};
LL dy[6]={2,0,-2,-2,0,2};

int main()
{
    LL i,j,res;
    while(scanf("%I64d",&n)!=EOF){
        if(n==0){
            printf("0 0\n");continue;
        }
        LL l=-1,r=577350300;
        while(l<r-1){
            LL m=(l+r)/2;
            if(3*m*m+3*m<n)
                l=m;
            else r=m;
        }
      //  printf("l=%I64d\n",l);
        while(3*l*l+3*l<=n) l++;
        while(3*l*l+3*l>=n) l--;
        n-=3*l*l+3*l;
        LL cnt=l+1;
     //   LL cnt=1;
     //   while(n>cnt*6){
     //       n-=cnt*6;cnt++;
     //   }
     //   printf("cnt=%I64d\n",cnt);
        LL x=(cnt-1)*2,y=0;
        n--;
        x++;y+=2;
        LL dc[6]={cnt-1,cnt,cnt,cnt,cnt,cnt};
        for(i=0;i<6;i++){
            if(n>=dc[i]){
                x+=dx[i]*dc[i];y+=dy[i]*dc[i];
                n-=dc[i];
            }else {
                x+=n*dx[i];y+=n*dy[i];
                break;
            }
        }
        printf("%I64d %I64d\n",x,y);
    }
    return 0;
}
