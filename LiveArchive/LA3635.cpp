/****************
*PID:la3635
*Auth:Jonariguez
*****************
¶þ·Ö
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define PI acos(-1)

const int maxn=10000+10;
int n,f;
double P[maxn];

bool C(double x){
    int i,cnt=0;
    for(i=0;i<n;i++)
        cnt+=floor(P[i]/x);
    return cnt>=f+1;
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&f);
        double r;
        for(i=0;i<n;i++){
            scanf("%lf",&r);
            P[i]=PI*r*r;
        }
        double L=0.0,R=400000000.0;
        for(i=0;i<200;i++){
            double m=(L+R)/2;
            if(C(m))
                L=m;
            else R=m;
        }
        printf("%.4f\n",L);
    }
    return 0;
}
