/****************
*PID:cf579B
*Auth:Jonariguez
*****************
按每个队的strength排序，从大到小处理
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=400+10;
int vis[maxn*2],a[maxn*2][maxn*2],b[maxn*2];
struct pp{
    int a,b,v;
    bool operator < (const pp &r) const {
        return v>r.v;
    }
}s[maxn*maxn];

int main()
{
    int i,j,n,k;
    while(scanf("%d",&n)!=EOF){
        int x;
        int cnt=0;
        for(i=2;i<=2*n;i++){
            for(j=1;j<i;j++){
                scanf("%d",&x);
                s[cnt].a=i;s[cnt].b=j;s[cnt++].v=x;
            }
        }
        sort(s,s+cnt);
        memset(vis,0,sizeof(vis));
        for(i=0;i<cnt;i++){
            if(vis[s[i].a]==0 && vis[s[i].b]==0){
                b[s[i].a]=s[i].b;b[s[i].b]=s[i].a;
                vis[s[i].a]=vis[s[i].b]=1;
            }
        }
        for(i=1;i<=2*n;i++)
            printf("%d ",b[i]);
        printf("\n");
    }
    return 0;
}
