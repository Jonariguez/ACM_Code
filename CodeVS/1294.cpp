/****************
*PID:cdvs1294
*Auth:Jonariguez
*****************
next_permutation(p+1,p+n+1)µÄÊ¹ÓÃ
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int p[11],vis[12],n;

void dfs(int cur){
    if(cur==n+1){
        for(int i=1;i<=n;i++)
            printf("%d%c",p[i],i==n?'\n':' ');
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            p[cur]=i;
            dfs(cur+1);
            vis[i]=0;
        }
    }
}

int main()
{
    int i,j;
    scanf("%d",&n);
    memset(vis,0,sizeof(vis));
    dfs(1);
    return 0;
}

/*
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++) p[i]=i;
    do{
        for(i=1;i<=n;i++)
            printf("%d%c",p[i],i==n?'\n':' ');
    }while(next_permutation(p+1,p+n+1));
    return 0;
}
*/
