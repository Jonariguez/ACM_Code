/****************
*PID:cdvs1075
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
int a[maxn];

int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
