/****************
*PID:hdu4349
*Auth:Jonariguez
*****************
����ҹ���:n�Ķ�������1�ĸ���Ϊcnt����Ϊ2^cnt
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

