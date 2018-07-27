/****************
*PID:630e
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
    LL x1,y1,x2,y2,res=0;
    while(scanf("%I64d%I64d%I64d%I64d",&x1,&y1,&x2,&y2)!=EOF){
        res=0;
        if(x1&1){
            if(x2&1){
                LL cnt=(x2-x1)/2+1;
                LL cnt2=(y2-y1)/2+1;
                res=cnt*cnt2+(cnt-1)*(cnt2-1);
            }else {
                LL cnt=(y2-y1)/2+1;
                res=cnt*(x2-x1+1);
            }
        }else {
            if(x2&1){
                LL cnt=(y2-y1)/2+1;
                res=cnt*(x2-x1+1);
            }else {
                LL cnt=(x2-x1)/2+1;
                LL cnt2=(y2-y1)/2+1;
                res=cnt*cnt2+(cnt-1)*(cnt2-1);
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}
