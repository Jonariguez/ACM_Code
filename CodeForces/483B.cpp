/****************
*PID:483b div2
*Auth:Jonariguez
*****************
¶þ·Ö
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

LL cnt1,cnt2,x,y,lcm;

bool C(LL v){
    if(v-v/x>=cnt1 && v-v/y>=cnt2 && v-v/lcm>=cnt1+cnt2)
        return true;
    return false;
}

int main()
{
    LL i,res;
    while(scanf("%I64d%I64d%I64d%I64d",&cnt1,&cnt2,&x,&y)!=EOF){
        lcm=x*y;
       // printf("%I64d\n",lcm);
        LL l=1,r=1e18;
        while(l<r){
            LL m=(l+r)/2;
            if(C(m))
                r=m;
            else l=m+1;
        }
        printf("%I64d\n",l);
    }
    return 0;
}
