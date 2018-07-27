/****************
*PID:uva11384
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

int div(int n){
    if(n==1 || n==2)
        return n;
    return div(n/2)+1;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",div(n));
    }
    return 0;
}
