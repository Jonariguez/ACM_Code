/****************
*PID:451a div2
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
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        n=min(n,m);
        if(n&1)
            printf("Akshat\n");
        else printf("Malvika\n");
    }
    return 0;
}
