/****************
*PID:cf579A
*Auth:Jonariguez
*****************
至少用几个，一定是exactly x个,
即求的是x的二进制中有几项，即几个1
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i,x,res;
    while(scanf("%d",&x)!=EOF){
        res=0;
        while(x){
            if(x&1) res++;
            x/=2;
        }
        printf("%d\n",res);
    }
    return 0;
}
