/****************
*PID:cdvs1540
*Auth:Jonariguez
*****************
带权并查集
维护信息：编号为x的战舰在该战舰所在列的前面的战舰数目
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=30000+10;
int par[maxn],sum[maxn],under[maxn];

int find(int x){
    if(x==par[x]) return x;
    int y=find(par[x]);
    under[x]+=under[par[x]];
    return par[x]=y;
}

void Union(int u,int v){
    u=find(u);v=find(v);
    par[u]=v;
    under[u]+=sum[v];
    sum[v]+=sum[u];     //注意上下两句不能颠倒
}

int main()
{
    int i,j,n,T;
    for(i=1;i<=30000;i++){
        par[i]=i;sum[i]=1;under[i]=0;
    }
    char str[4];
    scanf("%d",&T);
    while(T--){
        int a,b;
        scanf("%s%d%d",str,&a,&b);
        if(str[0]=='M')
            Union(a,b);
        else {
            int fa=find(a),fb=find(b);
            if(fa!=fb)
                printf("-1\n");
            else printf("%d\n",abs(under[a]-under[b])-1);
        }
    }
    return 0;
}

