/****************
*PID:cdvs3038
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
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int res=0;
        while(n!=1){
            if(n&1) n=3*n+1;
            else n/=2;
            res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
