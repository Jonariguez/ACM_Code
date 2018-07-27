/****************
*PID:630k
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

LL a[5]={2,3,5,7};

int main()
{
    LL i,j,n,m=4;
    while(scanf("%I64d",&n)!=EOF){
        LL res=0;
        for(i=0;i<(1<<m);i++){
            int cnt=0;
            LL lcm=1;
            for(j=0;j<m;j++){
                if((i>>j)&1){
                    cnt++;lcm*=a[j];
                }
            }
            if(lcm>n) continue;
            if(cnt&1)
                res-=n/lcm;
            else res+=n/lcm;
        }
        printf("%I64d\n",res);
    }
    return 0;
}
