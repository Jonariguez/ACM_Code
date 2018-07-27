/****************
*PID:630b
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

double quick_pow(int b){
    double res=1;
    double a=1.000000011;
    while(b){
        if(b&1)
            res=(res*a);
        b/=2;
        a=a*a;
    }
    return res;
}

int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    printf("%.7f\n",quick_pow(t)*n);
    return 0;
}
