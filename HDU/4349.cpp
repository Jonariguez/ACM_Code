/****************
*PID:hdu4349
*Auth:Jonariguez
*****************
打表找规律:n的二进制中1的个数为cnt，答案为2^cnt
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i,j,res,n;
    while(scanf("%d",&n)!=EOF){
        res=0;
        while(n){
            if(n&1)
                res++;
            n/=2;
        }
        printf("%d\n",(1<<res));
    }
    return 0;
}

