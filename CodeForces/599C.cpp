/****************
*PID:599c div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
const int INF=1e9+7;
int left[maxn],right[maxn],a[maxn];

int main()
{
    int i,j,n,res;
    while(scanf("%d",&n)!=EOF){
        left[0]=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            left[i]=max(left[i-1],a[i]);
        }
        right[n+1]=INF;
        for(i=n;i>=1;i--)
            right[i]=min(right[i+1],a[i]);
        res=0;
        for(i=1;i<n;i++)
            if(left[i]<=right[i+1]) res++;
        printf("%d\n",res+1);
    }
    return 0;
}
