/****************
*PID:hdu5630
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

int main()
{
    int i,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        printf("%d\n",n/2+m/2);
    }
    return 0;
}
