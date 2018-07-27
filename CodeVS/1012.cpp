/****************
*PID:cdvs1012
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
    int a,b,i,x,y;
    scanf("%d%d",&x,&y);
    if(y%x){
        puts("0");return 0;
    }
    int n=y/x;
    int cnt=0;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            cnt++;
            while(n%i==0) n/=i;
        }
    }
    if(n!=1) cnt++;
    printf("%lld\n",(1LL<<cnt));
    return 0;
}
