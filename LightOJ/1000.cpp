/****************
*PID:light1000
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
    int a,b,T,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++){
        scanf("%d%d",&a,&b);
        printf("Case %d: %d\n",i,a+b);
    }
    return 0;
}
