/****************
*PID:
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=100000+10;

int main()
{
    int i,j,n,res,x;
    scanf("%d",&n);
    res=0;
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        res^=x;
    }
    printf("%d\n",res);
    return 0;
}
