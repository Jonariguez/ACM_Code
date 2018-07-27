/****************
*PID:614a div2
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

int main()
{
    LL l,r,k,flag;
    while(scanf("%I64d%I64d%I64d",&l,&r,&k)!=EOF){
        flag=0;
        LL i,now=1;
        while(now<l) now*=k;
        while(now<=r){
            flag=1;printf("%I64d ",now);
            now*=k;
        }
        if(flag==0)
            puts("-1");
        else puts("");
    }
    return 0;
}
