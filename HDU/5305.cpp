#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=50;
int cnt[maxn],res,n,m;

struct rel{
    int x,y;
}s[30];

int online[maxn],offline[maxn];

void dfs(int cur){
    int i;
    if(cur==m){
        for(i=1;i<=n;i++)
            if(online[i]!=offline[i]) return ;
        res++;
        return ;
    }
    if(cur==m-1){
        for(i=1;i<=n;i++)
            if(online[i]<offline[i]) break;
        if(i>n){
            offline[s[cur].x]++;offline[s[cur].y]++;
            dfs(cur+1);
            offline[s[cur].x]--;offline[s[cur].y]--;
        }else {
            online[s[cur].x]++;online[s[cur].y]++;
            dfs(cur+1);
            online[s[cur].x]--;online[s[cur].y]--;
        }
        return ;
    }
    int u=s[cur].x,v=s[cur].y;
    if(offline[u]<cnt[u]/2 && offline[v]<cnt[v]/2){
        offline[u]++;offline[v]++;
        dfs(cur+1);
        offline[u]--;offline[v]--;
    }
    if(online[u]<cnt[u]/2 && online[v]<cnt[v]/2){
        online[u]++;online[v]++;
        dfs(cur+1);
        online[u]--;online[v]--;
    }

}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<m;i++){
            scanf("%d%d",&s[i].x,&s[i].y);
            cnt[s[i].x]++;cnt[s[i].y]++;
        }
        for(i=1;i<=n;i++)
            if(cnt[i]&1) break;
        if(i<=n){
            printf("0\n");
            continue;
        }
        res=0;
        memset(offline,0,sizeof(offline));
        memset(online,0,sizeof(online));
        dfs(0);
        printf("%d\n",res);
    }
    return 0;
}
