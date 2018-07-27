/****************
*PID:uva11889
*Auth:Jonariguez
*****************
B=(C/A)*gcd(A,B) B是(C/A)的整数倍，枚举B即可
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int i,T,a,c,b,t;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&a,&c);
        if(c%a){
            printf("NO SOLUTION\n");
            continue;
        }
        t=c/a;
        b=t;
        for(;;b+=t)
            if(gcd(b,a)*t==b)
                break;
        printf("%d\n",b);
    }
    return 0;
}
