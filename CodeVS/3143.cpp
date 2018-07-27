/****************
*PID:cdvs3143/1501
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int left[20],right[20];

void pre(int u){
    if(u==0) return ;
    printf("%d ",u);
    pre(left[u]);
    pre(right[u]);
}

void mid(int u){
    if(u==0) return ;
    mid(left[u]);
    printf("%d ",u);
    mid(right[u]);
}

void post(int u){
    if(u==0) return ;
    post(left[u]);
    post(right[u]);
    printf("%d ",u);
}

int deep[20];

int dfs(int u,int d){
    if(u==0) return 0;
    deep[d]++;
    return max(dfs(left[u],d+1),dfs(right[u],d+1))+1;
}

int main()
{
    int i,j,n;
    memset(left,0,sizeof(left));
    memset(right,0,sizeof(right));
    memset(deep,0,sizeof(deep));
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        left[i]=a;right[i]=b;
    }
  /*  pre(1);puts("");
    mid(1);puts("");
    post(1);puts("");*/
    int D=dfs(1,1),res=0;
    for(i=1;i<=19;i++)
        res=max(res,deep[i]);
    printf("%d %d\n",res,D);
    return 0;
}
