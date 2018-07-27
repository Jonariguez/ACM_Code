/****************
*PID:467a div2
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
    while(scanf("%d",&n)!=EOF){
        int res=0;
        for(i=1;i<=n;i++){
            int p,q;
            scanf("%d%d",&p,&q);
            if(q>p+1) res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
