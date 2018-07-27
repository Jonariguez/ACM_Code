/****************
*PID:450a div2
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
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int res=0,cnt=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i-1]);
        }
        i=0;
        while(cnt<n-1){
            if(a[i]>0 && (a[i]-=m)<=0)
                cnt++;
            i++;i%=n;
        }
        for(i=0;i<n;i++) if(a[i]>0) break;
        printf("%d\n",i+1);
    }
    return 0;
}
