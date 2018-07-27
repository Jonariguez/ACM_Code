#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

ll fac[40],g[40],f[40];

void init(){
    int i,j;
    fac[0]=1;
    for(i=1;i<=30;i++)
        fac[i]=fac[i-1]*2;
    g[0]=1;g[1]=2;g[2]=4;
    f[0]=f[1]=f[2]=0;
    for(i=3;i<=30;i++){
        f[i]=fac[i-3];
        for(j=2;j<=i-2;j++)
            f[i]+=g[j-2]*fac[i-j-2];
        g[i]=fac[i]-f[i];
    }
}

int main()
{
    int n;
    init();
    while(scanf("%d",&n),n)
        printf("%lld\n",f[n]);
    return 0;
}
