/****************
*PID:604a div2
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
int m[10],w[10],s[10];

int main()
{
    int i,j,n,hs,hu;
    for(i=1;i<=5;i++)
        scanf("%d",&m[i]);
    for(i=1;i<=5;i++)
        scanf("%d",&w[i]);
    s[1]=500;s[2]=1000;s[3]=1500;s[4]=2000;s[5]=2500;
    scanf("%d%d",&hs,&hu);
    LL res=0;
    for(i=1;i<=5;i++)
        res+=max(s[i]*3/10,(250-m[i])*s[i]/250-50*w[i]);
    res+=hs*100;
    res-=hu*50;
    printf("%I64d\n",res);
    return 0;
}
