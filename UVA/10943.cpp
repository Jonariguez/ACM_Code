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

const int MOD=1000000;

int f[210][210];

int main()
{
    int i,j,n,k;
    for(i=0;i<=200;i++){
        for(j=0;j<=i;j++){
            if(j==0 || j==i)
                f[i][j]=1;
            else
                f[i][j]=(f[i-1][j]+f[i-1][j-1])%MOD;
        }
    }
    while(scanf("%d%d",&n,&k)){
        if(n==0 && k==0) break;
        printf("%d\n",f[n+k-1][k-1]);
    }
    return 0;
}
