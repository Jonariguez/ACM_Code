/****************
*PID:hdu5605
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
    int i,j,x,y,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&x,&y);
        printf("%d\n",2*x*y);
    }
    return 0;
}
