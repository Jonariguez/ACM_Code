/****************
*PID:uva10370
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
double a[maxn];

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        double sum=0.0;
        for(i=0;i<n;i++){
            scanf("%lf",&a[i]);
            sum+=a[i];
        }
        sum/=n;
        int res=0;
        for(i=0;i<n;i++)
            if(a[i]-sum>0)
                res++;
        printf("%.3f%%\n",(double)res/n*100);
    }
    return 0;
}
