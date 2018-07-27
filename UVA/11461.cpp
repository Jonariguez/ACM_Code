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
int sum[maxn];

int main()
{
    int i,j,a,b;
    for(i=1;i<=1000;i++)
        if(i*i<=100000)
            sum[i*i]++;
    sum[0]=0;
    for(i=1;i<=100000;i++) sum[i]+=sum[i-1];
    while(scanf("%d%d",&a,&b)){
        if(a==0 && b==0) break;
        printf("%d\n",sum[b]-sum[a-1]);
    }
    return 0;
}
