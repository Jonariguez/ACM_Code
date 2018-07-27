/****************
*PID:hdu2007
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
    int i,j,sum1,sum2,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n>m){
            int t=n;n=m;m=t;
        }
        sum1=0;sum2=0;
        for(i=n;i<=m;i++){
            if(i&1) sum1+=i*i*i;
            else sum2+=i*i;
        }
        printf("%d %d\n",sum2,sum1);
    }
    return 0;
}
