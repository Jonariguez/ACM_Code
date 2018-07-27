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
    int i,a=1,b=1,c;
    int n;
    scanf("%d",&n);
    if(n<=2){
        printf("1\n");return 0;
    }
    for(i=2;i<n;i++){
        c=a+b;a=b;b=c;
    }
    printf("%d\n",c);
    return 0;
}
