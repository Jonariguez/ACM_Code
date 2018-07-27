/****************
*PID:
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

const int maxn=1000+10;
int a[maxn],vis[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int res=0,cnt=0;
        sort(a+1,a+n+1);
        while(cnt<n){
            i=1;
            while(i<=n && vis[i]==1) i++;
            if(i>n) break;
            vis[i]=1;cnt++;
            int last=a[i++];
            for(;i<=n;i++){
                if(vis[i]==0 && a[i]>last){
                    vis[i]=1;res++;cnt++;last=a[i];
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
