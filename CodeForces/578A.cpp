/****************
*PID:cf578A
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define eps 1e-10

int main()
{
    int i,a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        int k=a/b;
        if(a<b)
            printf("-1\n");
        else {
            if(k%2==1)
                k++;
            double res=(a+b)/(double)k;
            printf("%.10f\n",res);
        }
    }
    return 0;
}
