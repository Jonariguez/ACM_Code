/****************
*PID:576A
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
int a[maxn];
int vis[maxn];

int main()
{
    int i,j,n,res,k;
    while(scanf("%d",&n)!=EOF){
        memset(vis,0,sizeof(vis));
        res=0;
        for(i=2;i<=n;i++){
            if(vis[i]==0){
                int x=i;
                for(;x<=n;x*=i)
                    a[res++]=x;
                for(j=i*2;j<=n;j+=i)
                    vis[j]=1;
            }
        }
        printf("%d\n",res);
        for(i=0;i<res;i++)
            printf("%d%c",a[i],i==res-1?'\n':' ');
    }
    return 0;
}
