#include <stdio.h>
#include <string.h>
int n,is[40],a[20],vis[20];

int is_prime(int x){
    int i;
    for(i=2;i*i<=x;i++)
        if(x%i==0)
            return 0;
    return 1;
}

void dfs(int cur){
    int i;
    if(cur==n+1 && is[a[1]+a[n]]){
        for(i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
        return ;
    }
    for(i=2;i<=n;i++)
        if(vis[i]==0 && is[i+a[cur-1]]){
            a[cur]=i;
            vis[i]=1;
            dfs(cur+1);
            vis[i]=0;
        }
}

int main()
{
    int i,kcase=1;
    for(i=2;i<33;i++)
        is[i]=is_prime(i);
    while(scanf("%d",&n)!=EOF){
        memset(vis,0,sizeof(vis));
        if(kcase>1) printf("\n");
        a[1]=1;     //一定先把1放在第一位
        printf("Case %d:\n",kcase++);
        dfs(2);
    }
    return 0;
}
