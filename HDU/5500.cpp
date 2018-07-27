/****************
*PID:hdu5500
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int a[50];

int main()
{
    int i,j,res,now,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        now=n;
        i=n-1;
        res=0;
        while(i>=0){
            for(;i>=0;i--){
                if(a[i]==now) break;
                res++;
            }
            i--;now--;
        }
        printf("%d\n",res);
    }
    return 0;
}
