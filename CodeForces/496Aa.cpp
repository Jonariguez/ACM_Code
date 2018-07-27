/****************
*PID:496a div2
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
int a[maxn];
int main()
{
    int i,j,n,res;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        res=10000;
        for(j=2;j<n;j++){
            int t=0;
            for(i=1;i<n;i++)
                if(i==j)
                    t=max(t,a[i+1]-a[i-1]);
                else
                    t=max(t,a[i+1]-a[i]);
            res=min(res,t);
        }
        printf("%d\n",res);
    }
    return 0;
}
