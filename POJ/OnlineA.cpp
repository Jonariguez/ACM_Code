/****************
*PID:onlineA
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int a[10];

int main()
{
    int i,j,k,T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        if(n==2){
            if(a[1]<a[2])
                printf("0\n");
            else printf("1\n");
        }else {
            k=0;
            for(i=2;i<=n;i++)
                for(j=1;j<i;j++)
                    if(a[j]>a[i])
                    k++;
            printf("%d\n",k*4);
        }
    }
    return 0;
}
