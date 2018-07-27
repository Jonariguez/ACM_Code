/****************
*PID:527A div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef __int64 LL;

int main()
{
    LL a,b,res;
    while(scanf("%I64d%I64d",&a,&b)!=EOF){
        res=0;
        while(a!=0 && b!=0){
            if(a>b){
                res+=a/b;a%=b;
            }else {
                res+=b/a;b%=a;
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}
