/****************
*PID:hdu5523
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
    int i,j,n,s,t;
    while(scanf("%d%d%d",&n,&s,&t)!=EOF){
        if(n==1)
            printf("0\n");
        else if(s==t)
            printf("-1\n");
        else if(s==1 && t==n || s==n && t==1)
            printf("0\n");
        else if(abs(s-t)==1 || s==1 || s==n)
            printf("1\n");
        else printf("2\n");
    }
    return 0;
}
