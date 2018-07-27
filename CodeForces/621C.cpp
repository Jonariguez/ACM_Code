/****************
*PID:621c div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;
double yes[maxn],no[maxn];

int main()
{
    int i,j,n,p;
    while(scanf("%d%d",&n,&p)!=EOF){
        int l,r;
        for(i=1;i<=n;i++){
            scanf("%d%d",&l,&r);
            int cnt=r/p-(l-1)/p;
            yes[i]=(double)cnt/(r-l+1);
            yes[i]=1.0-yes[i];
        }
        double res=0;
        for(i=1;i<n;i++)
            res+=(1-yes[i]*yes[i+1])*2000;
        res+=(1-yes[n]*yes[1])*2000;
        printf("%.7f\n",res);
    }
    return 0;
}
