/****************
*PID:uva11636
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
    int i,kcase=1,n,res;
    while(scanf("%d",&n) && n>=0){
        res=0;
        int t=1;
        while(t<n){
            res++;t*=2;
        }
        printf("Case %d: %d\n",kcase++,res);
    }
    return 0;
}
