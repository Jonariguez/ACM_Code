/****************
*PID:601a div2
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
    int i,n;
    while(scanf("%d",&n)!=EOF){
        if(n&1)
            printf("0\n");
        else {
            n/=2;
            printf("%d\n",(n-1)/2);
        }
    }
    return 0;
}
