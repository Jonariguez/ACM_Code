/****************
*PID:uva10970
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
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==1)
            printf("%d\n",m-1);
        else if(m==1)
            printf("%d\n",n-1);
        else
            printf("%d\n",min(n*(m-1)+n-1,m*(n-1)+m-1));

    }
    return 0;
}
