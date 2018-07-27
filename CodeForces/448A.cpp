/****************
*PID:448a div2
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

const int maxn=100000+10;

int main()
{
    int i,j,n,m;
    int sum1=0,sum2=0;
    for(i=1;i<=3;i++){
        scanf("%d",&j);
        sum1+=j;
    }
    for(i=1;i<=3;i++){
        scanf("%d",&j);
        sum2+=j;
    }
    scanf("%d",&n);
    if((sum1+4)/5+(sum2+9)/10<=n)
        puts("YES");
    else puts("NO");
    return 0;
}
