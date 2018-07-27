#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int i,j,n,T,res;
    double t;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        t=0;
        for(i=1;i<=n;i++)
            t+=log10(i);
        res=(int)t+1;
        printf("%d\n",res);
    }
    return 0;
}
