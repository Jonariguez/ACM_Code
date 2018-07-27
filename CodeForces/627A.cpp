/****************
*PID:627a 8vc
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

LL x,s;

int main()
{
    int i,j;
    while(scanf("%I64d%I64d",&s,&x)!=EOF){
        LL temp=s-x;
        if(temp<0 || temp&1){
            puts("0");continue;
        }
        temp/=2;
        LL res,cnt=0;
        int yes=1;
        for(i=0;i<44;i++){
            if(temp&(1LL<<i)){
                if(x&(1LL<<i)){
                    yes=0;break;
                }
            }else {
                if(x&(1LL<<i)) cnt++;
            }
        }
        if(yes==0)
            puts("0");
        else {
            res=(1LL<<cnt);
            if(s==x) res-=2;
            printf("%I64d\n",res);
        }
    }
    return 0;
}
