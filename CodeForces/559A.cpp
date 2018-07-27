/****************
*PID:559A div1
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Pow(int x){
    return x*x;
}

int main()
{
    int i,x,a[7],sum=0;
    for(i=1;i<=6;i++){
        scanf("%d",&a[i]);
        if(i<=3) sum+=a[i];
    }
    printf("%d\n",Pow(sum)-Pow(a[1])-Pow(a[3])-Pow(a[5]));
    return 0;
}
