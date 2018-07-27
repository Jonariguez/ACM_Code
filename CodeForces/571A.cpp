/****************
*PID:571a div1
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

int main()
{
    LL a,b,c,l,la,lb,lc;
    while(scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&l)!=EOF){
        LL sum=0;
        for(la=0;la<=l;la++)
            sum+=(la+1)*(la+2)/2;
        for(la=0;la<=l;la++){
            LL x=min(l-la,a-b-c+la);
            if(x>=0)
                sum-=(x+1)*(x+2)/2;
        }
        for(lb=0;lb<=l;lb++){
            LL x=min(l-lb,b-a-c+lb);
            if(x>=0)
                sum-=(x+1)*(x+2)/2;
        }
        for(lc=0;lc<=l;lc++){
            LL x=min(l-lc,c-a-b+lc);
            if(x>=0)
                sum-=(x+1)*(x+2)/2;
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
