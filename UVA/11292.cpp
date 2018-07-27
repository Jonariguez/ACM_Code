/****************
*PID:uva11292
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=20000+10;
int a[maxn],b[maxn];

int main()
{
    int i,j,n,m,res;
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<m;i++)
            scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+m);
        int cur=0;
        res=0;
        for(i=0;i<m;i++){
            if(b[i]>=a[cur]){
                res+=b[i];
                cur++;
            }
            if(cur==n) break;
        }
        if(cur<n)
            printf("Loowater is doomed!\n");
        else printf("%d\n",res);
    }
    return 0;
}
