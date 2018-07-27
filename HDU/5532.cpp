/****************
*PID:hdu5532
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
int a[maxn],left[maxn],right[maxn];

int main()
{
    int i,j,n,m,res,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        if(n<=3){
            puts("YES");continue;
        }
        left[1]=0;
        int last=0;
        for(i=2;i<=n;i++){
            left[i]=last+1;
            if(a[i]>=a[i-1]){
               // left[i]=last+1;
                last++;
            }else last=0;
        }
        right[n]=0;last=0;
        for(i=n-1;i>=1;i--){
            right[i]=last+1;
            if(a[i]<=a[i+1])
                last++;
            else last=0;
        }
     /*   for(i=1;i<=n;i++){
            printf("%d ",left[i]);
        }
        puts("");
        for(i=1;i<=n;i++){
            printf("%d ",right[i]);
        }
        puts("");*/
        int yes=0;
        a[0]=-1;a[n+1]=maxn;
        for(i=1;i<=n;i++)
            if(left[i]+right[i]==n-1 && a[i-1]<=a[i+1]){
                yes=1;break;
            }
        if(yes){
            puts("YES");continue;
        }
        left[1]=0;
        last=0;
        for(i=2;i<=n;i++){
            left[i]=last+1;
            if(a[i]<=a[i-1]){
               // left[i]=last+1;
                last++;
            }else last=0;
        }
        right[n]=0;last=0;
        for(i=n-1;i>=1;i--){
            right[i]=last+1;
            if(a[i]>=a[i+1])
                last++;
            else last=0;
        }
        yes=0;
        a[0]=maxn;a[n+1]=-1;
        for(i=1;i<=n;i++)
            if(left[i]+right[i]==n-1 && a[i-1]>=a[i+1]){
                yes=1;break;
            }
        if(yes)
            puts("YES");
        else puts("NO");
    }
    return 0;
}

