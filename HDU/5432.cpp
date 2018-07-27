/****************
*PID:hdu5432
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10000+10;
int a[maxn],b[maxn],n;
double sum;

bool C(double x){
    double cnt=0.0;
    for(int i=0;i<n;i++){
        if(x>a[i]) continue;
        double y=(a[i]-x)/a[i]*b[i];
        cnt+=y*y*(a[i]-x)/3;
    }
    return cnt>sum/2;
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
            scanf("%d",&b[i]);
        sum=0.0;
        for(i=0;i<n;i++)
            sum+=b[i]*b[i]*a[i]*1.0/3;
        double l=0.0,r=1000.0;
        for(i=0;i<50;i++){
            int m=(l+r)/2;
            if(C(m)) l=m;
            else r=m;
        }
        printf("%d\n",(int)l);
    }
    return 0;
}
