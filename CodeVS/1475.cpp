/****************
*PID:cdvs1475
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

char str[1000];

int main()
{
    int i,j,n,m,now,res;
    res=0;now=1;
    scanf("%s%d",str+1,&m);
    n=strlen(str+1);
    for(i=n;i>=1;i--){
        int x;
        if(str[i]>='0' && str[i]<='9')
            x=str[i]-'0';
        else x=str[i]-'A'+10;
        res+=x*now;
        now*=m;
    }
    printf("%d\n",res);
    return 0;
}
