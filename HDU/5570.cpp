/****************
*PID:hdu5570
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
double a[maxn][maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++){
            double sum=0.0;
            for(j=1;j<=m;j++){
                scanf("%lf",&a[i][j]);
                sum+=a[i][j];
            }
            for(j=1;j<=m;j++)
                a[i][j]/=sum;
        }
        double sum,res=0.0;
        for(i=1;i<=m;i++){
            sum=0;
            for(j=1;j<=n;j++){
                sum+=a[j][i];
                res+=a[j][i];
                res-=a[j][i]*a[j][i];
            }
            res+=sum*sum;
        }
        printf("%.2f\n",res);
    }
    return 0;
}
