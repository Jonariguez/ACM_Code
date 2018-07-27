#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
double v[maxn],Log[maxn];

void pre_solve(){
    int i;
    Log[0]=0;
    for(i=1;i<=100000;i++)
        Log[i]=Log[i-1]+log(i);
}

int main()
{
    int i,j,n,T;
    pre_solve();
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        double res=0.0;
        int t=n/2;
        res=Log[n-2]-Log[t-1]*2;
        res+=(2*t-2)*log(0.5);
        res=exp(res);
        printf("%.4f\n",1-res);
    }
    return 0;
}
