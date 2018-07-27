/****************
*PID:478a div2
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
int a[maxn];

int main()
{
    int i,j,n,m;
    int res=0;
    for(i=1;i<=5;i++){
        int x;
        scanf("%d",&x);
        res+=x;
    }
    if(res%5 || res==0)
        puts("-1");
    else printf("%d\n",res/5);
    return 0;
}
