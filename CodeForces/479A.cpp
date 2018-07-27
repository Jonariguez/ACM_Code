/****************
*PID:479a div2
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
    int a,b,c,res;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF){
        res=0;
        res=max(res,a+b+c);
        res=max(res,a*b+c);
        res=max(res,a+b*c);
        res=max(res,a*b*c);
        res=max(res,a*(b+c));
        res=max(res,(a+b)*c);
        printf("%d\n",res);
    }
    return 0;
}
