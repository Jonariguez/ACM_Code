#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

long long a[30][30];

int main()
{
    int i,T,j,t;
    scanf("%d",&T);
    while(T--){
        for(i=1;i<=9;i+=2)
            for(j=1;j<=i;j+=2)
                scanf("%lld",&a[i][j]);
        for(j=2;j<9;j+=2)
            a[9][j]=(a[7][j-1]-a[9][j-1]-a[9][j+1])/2;
        for(i=8;i>0;i--)
            for(j=1;j<=i;j++)
                a[i][j]=a[i+1][j]+a[i+1][j+1];
        for(i=1;i<=9;i++)
            for(j=1;j<=i;j++)
                printf("%lld%c",a[i][j],j==i?'\n':' ');
    }
    return 0;
}
