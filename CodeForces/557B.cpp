#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=100000+5;
int a[maxn*2];

int main()
{
    int i,j,n,w;
    while(scanf("%d%d",&n,&w)!=EOF){
        for(i=1;i<=2*n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+2*n+1);
        double res=min((double)a[1],(double)a[n+1]/2);
        res=res*3*n;
        if(res>w)
            res=(long double)w;
        printf("%.7f\n",(double)res);
    }
    return 0;
}
