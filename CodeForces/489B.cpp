/****************
*PID:489b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
int a[maxn],b[maxn];

int main()
{
    int i,j,n,m,res;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for(i=1;i<=m;i++)
            scanf("%d",&b[i]);
        sort(a+1,a+n+1);
        sort(b+1,b+m+1);
        res=0;
        j=1;
        for(i=1;i<=n;i++){
            while(j<=m && b[j]<=a[i]+1){
                if(abs(a[i]-b[j])<=1) break;
                j++;
            }
            if(j>m) break;
            if(abs(a[i]-b[j])<=1){
                res++;
                j++;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
