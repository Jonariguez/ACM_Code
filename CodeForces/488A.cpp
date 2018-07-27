/****************
*PID:488a div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool check(int n){
    while(n){
        int t=n%10;
        if(t==8) return true;
        n/=10;
    }
    return false;
}

int main()
{
    int i,n,res;
    while(scanf("%d",&n)!=EOF){
        res=1;n++;
        while(!check(abs(n))){
            n++;res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
