/****************
*PID:507c div2
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
LL fact[60];

int main()
{
    LL i,h,n,res;
    fact[0]=1;
    for(i=1;i<=51;i++)
        fact[i]=fact[i-1]*2;
    while(scanf("%I64d%I64d",&h,&n)!=EOF){
        LL now=1,d=0,deep=0;
        res=0;
        while(deep!=h){
            LL cnt=fact[h-deep]/2;
            res++;
            if(n>cnt && d==0){
                res+=fact[h-deep]-1;
                deep++;d=0;n-=cnt;
            }else if(n>cnt && d==1){
                deep++;d=0;n-=cnt;
            }else if(n<=cnt && d==0){
                d=1;deep++;
            }else {
                res+=fact[h-deep]-1;
                deep++;d=1;
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}

