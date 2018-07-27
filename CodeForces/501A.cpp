/****************
*PID:501a div2
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
    int a,b,c,d;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF){
        int res1=max(a*3/10,a-a/250*c);
        int res2=max(b*3/10,b-b/250*d);
        if(res1==res2)
            printf("Tie\n");
        else if(res1>res2)
            printf("Misha\n");
        else printf("Vasya\n");
    }
    return 0;
}
