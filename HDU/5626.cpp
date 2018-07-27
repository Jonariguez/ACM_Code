/****************
*PID:hdu5626
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

const int maxn=1000000+5;
const LL INF=1e18;
LL x[maxn],y[maxn];
long long seed;
inline long long rand(long long l, long long r) {
  static long long mo=1e9+7, g=78125;
  return l+((seed*=g)%=mo)%(r-l+1);
}

int main()
{
    LL i,j,n,res;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d%I64d",&n,&seed);
        for (i=0;i<n;i++){
            x[i]=rand(-1000000000, 1000000000);
            y[i]=rand(-1000000000, 1000000000);
        }
        res=0;
        LL l,r,now;
        for(i=0;i<4;i++){
            l=INF;r=-INF;
            for(j=0;j<n;j++){
                now=0;
                if(i&1)
                    now+=x[j];
                else now-=x[j];
                if(i&2)
                    now+=y[j];
                else now-=y[j];
                l=min(l,now);
                r=max(r,now);
            }
         //   printf("r=%I64d l=%I64d\n",r,l);
            res=max(res,r-l);
        }
        printf("%I64d\n",res);
    }
    return 0;
}
