/****************
*PID:577A
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i,n,res,x;
    while(scanf("%d%d",&n,&x)!=EOF){
        res=0;
        for(i=1;i<=n;i++)
            if(x%i==0 && x/i<=n)
                res++;
        printf("%d\n",res);
    }
    return 0;
}
