/****************
*PID:613a div2
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
        memset(a,0,sizeof(a));
        int x,cnt=0,k;
        for(i=1;i<=n;i++){
            scanf("%d",&k);
            while(k--){
                scanf("%d",&x);
                if(a[x]==0) cnt++;
                a[x]=1;
            }
        }
        if(cnt==m) puts("YES");
        else puts("NO");
    }
    return 0;
}
