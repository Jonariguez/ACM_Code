/****************
*PID:cdvs1083
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
    int i,j,n,k;
    scanf("%d",&n);
    int sum=0;
    k=1;
    while(sum<n){
        sum+=k;k++;
    }
    sum-=n-1;
    if(k&1)
        printf("%d/%d\n",k-sum,sum);
    else printf("%d/%d\n",sum,k-sum);
    return 0;
}
