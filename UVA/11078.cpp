/****************
*PID:uva11078
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
    int i,j,T,res,x,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int maxv,minv;
        scanf("%d",&maxv);
        minv=maxv;
        res=-1500000;
        for(i=1;i<n;i++){
            scanf("%d",&x);
            res=max(res,maxv-x);
            maxv=max(maxv,x);
        }
        printf("%d\n",res);
    }
    return 0;
}
