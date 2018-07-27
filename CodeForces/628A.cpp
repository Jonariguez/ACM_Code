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

int main()
{
    int i,j,n,b,p,x,y;
    while(scanf("%d%d%d",&n,&b,&p)!=EOF){
        y=n*p;
        x=0;
        int now=1;
        while(n!=1){
            now=1;
            while(now<=n) now*=2;
            now/=2;
            x+=now*b;
            x+=now/2;
            now/=2;
            n-=now;
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}
