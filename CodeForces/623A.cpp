/****************
*PID:623a div1
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

const int maxn=500+5;
const int maxm=250000+10;
int head[maxn],vv[maxm],nxt[maxm],a[maxn],mp[maxn][maxn],deg[maxn],e,yes;

void add(int u,int v){
    vv[e]=v;nxt[e]=head[u];head[u]=e++;
}


int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int u,v;
        memset(head,0,sizeof(head));
        memset(mp,0,sizeof(mp));
        memset(deg,0,sizeof(deg));
        e=1;
        for(i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            add(u,v);add(v,u);
            mp[u][v]=mp[v][u]=1;
            deg[u]++;deg[v]++;
        }
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++){
            if(deg[i]==n-1) a[i]=2;
        }
        int now=0;
        for(i=1;i<=n;i++)
            if(a[i]!=2){
                now=i;break;
            }
        if(now==0){
            printf("Yes\n");
            for(i=1;i<=n;i++) printf("b");
            puts("");
            continue;
        }
        a[now]=1;
        for(i=1;i<=n;i++){
            if(now==i) continue;
            if(!mp[now][i]) a[i]=3;
            else if(a[i]==0) a[i]=1;
        }
        yes=1;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(i==j) continue;
                if(mp[i][j]){
                    if(abs(a[i]-a[j])>1){
                        yes=0;break;
                    }
                }else {
                    if(abs(a[i]-a[j])<=1){
                        yes=0;break;
                    }
                }
            }
            if(yes==0) break;
        }
        if(yes==0)
            puts("No");
        else {
            puts("Yes");
            for(i=1;i<=n;i++)
                printf("%c",a[i]-1+'a');
            puts("");
        }
    }
    return 0;
}

