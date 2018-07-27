/****************
*PID:uva1442
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=1000000+10;
int n,p[maxn],s[maxn],left[maxn],right[maxn];

int main()
{
    int i,j,res,T_T;
    scanf("%d",&T_T);
    while(T_T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%d",&p[i]);
        for(i=1;i<=n;i++) scanf("%d",&s[i]);
        int last=s[1];
        for(i=1;i<=n;i++){
            left[i]=last;
            last=min(last,s[i]);
            last=max(last,p[i]);
        }
        last=s[n];
        for(i=n;i>=1;i--){
            right[i]=last;
            last=min(last,s[i]);
            last=max(last,p[i]);
        }
        res=0;
        for(i=1;i<=n;i++){
            int v;
            res+=(v=max(0,min(s[i]-p[i],min(left[i],right[i])-p[i])));
          //  printf("%d ",v);
        }
        printf("%d\n",res);
    }
    return 0;
}
