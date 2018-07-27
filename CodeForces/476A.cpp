/****************
*PID:476a div2
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
        int res=0,now=0;
        while(now<(n+1)/2){
            now+=m;
        }
        if(now>n)
            puts("-1");
        else
            printf("%d\n",now);
    }
    return 0;
}
