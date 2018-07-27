/****************
*PID:584A div1
*Auth:Jonariguez
*****************
n=1 t=10时无解
否则解为tttttt... 或者1000000...
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i,n,t;
    while(scanf("%d%d",&n,&t)!=EOF){
        if(n==1 && t==10){
            printf("-1\n");
            continue;
        }
        if(t==10){
            printf("1");
            for(i=1;i<n;i++)
                printf("0");
        }else
            for(i=0;i<n;i++)
                printf("%d",t);
        printf("\n");
    }
    return 0;
}
