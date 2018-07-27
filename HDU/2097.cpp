/****************
*PID:hdu2097
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int res;

bool cal(int n,int bit){
    int sum=0;
    while(n){
        sum+=n%bit;n/=bit;
    }
    return sum==res;
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n),n){
        int t=n;
        res=0;
        while(t){
            res+=t%10;t/=10;
        }
        if(cal(n,12) && cal(n,16))
            printf("%d is a Sky Number.\n",n);
        else printf("%d is not a Sky Number.\n",n);
    }
    return 0;
}
