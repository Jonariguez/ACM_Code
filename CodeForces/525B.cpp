/****************
*PID:525b div2
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

const int maxn=200000+10;
char str[maxn];
int vis[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%s",str+1)!=EOF){
        n=strlen(str+1);
        scanf("%d",&m);
        memset(vis,0,sizeof(vis));
        int a,b;
        while(m--){
            scanf("%d",&a);
            b=n-a+1;
            vis[a]++;vis[b+1]--;
        }
        vis[0]=0;
        for(i=1;i<=n;i++)
            vis[i]+=vis[i-1];
        for(i=1;i<=n;i++){
            if(vis[i]&1) printf("%c",str[n-i+1]);
            else printf("%c",str[i]);
        }
    }
    return 0;
}
