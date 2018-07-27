/****************
*ID:cf570B
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
    int i,j,k,a,m,n;
    while(scanf("%d%d",&n,&m)!=EOF){
        int x=n-m;
        if(n==1)
            a=1;
        else if(m==1)
            a=2;
        else if(m==n)
            a=n-1;
        else if(x<=m-1)
            a=m-1;
        else
            a=m+1;
        printf("%d\n",a);
    }
    return 0;
}

