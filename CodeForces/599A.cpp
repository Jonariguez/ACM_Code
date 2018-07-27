/****************
*PID:599a div2
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
    int i,j,n,a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF){
        int res=a*2+2*b;
        res=min(res,a+b+c);
        res=min(res,a+c*2+a);
        res=min(res,b*2+c*2);
        printf("%d\n",res);
    }
    return 0;
}
