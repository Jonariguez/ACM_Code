/****************
*PID:poj1017
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

LL a[7];

int main()
{
    LL i,j,res,now;
    while(scanf("%lld",&a[1])){
        now=a[1];
        for(i=2;i<=6;i++){
            scanf("%lld",&a[i]);
            now+=a[i];
        }
        if(now==0) break;
        res=a[6]+a[5]+a[4];
        a[1]=max(a[1]-a[5]*11,0LL);
        now=a[4]*5;
      //  a[2]=max(a[2]-a[4]*5,0LL);
      //  res+=(a[1]+a[2]*4+a[3]*9+35)/36;
        if(a[2]>=a[4]*5)
            a[2]-=a[4]*5;
        else {
            a[1]=max(a[1]-(now-a[2])*4,0LL);
            a[2]=0;
        }
        res+=(a[3]+3)/4;
        LL cnt=a[3]%4;
        if(cnt){
            if(cnt==1){
                if(a[2]>=5){
                    a[2]-=5;a[1]=max(a[1]-7,0LL);
                }
                else {
                    a[1]=max(0LL,a[1]-(27-a[2]*4));
                    a[2]=0;
                }
            }else if(cnt==2){
                if(a[2]>=3){
                    a[2]-=3;
                    a[1]=max(a[1]-6,0LL);
                }
                else {
                    a[1]=max(0LL,a[1]-(18-a[2]*4));
                    a[2]=0;
                }
            }else if(cnt==3){
                if(a[2]>=1){
                    a[2]-=1;a[1]=max(a[1]-5,0LL);
                }
                else {
                    a[1]=max(0LL,a[1]-(9-a[2]*4));
                    a[2]=0;
                }
            }
        }
        res+=(a[1]+a[2]*4+35)/36;
        printf("%lld\n",res);
    }
    return 0;
}
