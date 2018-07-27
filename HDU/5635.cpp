/****************
*PID:hdu5635
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

const int maxn=100000+5;
const LL MOD=1e9+7;
LL a[maxn];

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<n;i++)
            scanf("%lld",&a[i]);
        int cnt=1,yes=1;
        LL last=a[n-1];
        if(last>=2){
            puts("0");continue;
        }
        for(i=n-1;i>=1;i--){
            if(a[i]==0) cnt++;
            if(i<n-1){
                if(a[i]!=last+1 && a[i]!=0){
                    yes=0;break;
                }
                last=a[i];
            }
        }
        if(yes==0){
            puts("0");continue;
        }
        LL res=26;
        for(i=2;i<=cnt;i++){
            res=res*25;
            res%=MOD;
        }
        printf("%lld\n",res);
    }
    return 0;
}
