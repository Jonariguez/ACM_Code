/****************
*PID:poj1852
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
    int i,l,n,T,maxv,minv;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&l,&n);
        int x;
        maxv=0;minv=0;
        for(i=0;i<n;i++){
            scanf("%d",&x);
            maxv=max(maxv,max(x,l-x));
            minv=max(minv,min(x,l-x));
        }
        printf("%d %d\n",minv,maxv);
    }
    return 0;
}
