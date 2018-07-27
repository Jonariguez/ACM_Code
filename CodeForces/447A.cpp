/****************
*PID:447a div2
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
    int i,j,n,m,p;
    while(scanf("%d%d",&p,&n)!=EOF){
        int f=0;
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++){
            scanf("%d",&m);
            if(f) continue;
            if(a[m%p]){
                f=i;continue;
            }
            a[m%p]=1;
        }
        if(f==0) f=-1;
        printf("%d\n",f);
    }
    return 0;
}
