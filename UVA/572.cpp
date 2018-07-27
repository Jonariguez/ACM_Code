#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100+10;
char a[maxn][maxn];
int n,m;

void dfs(int x,int y){
    if(x<1 || x>m || y<1 || y>n) return ;
    if(a[x][y]=='*') return ;
    a[x][y]='*';
    dfs(x-1,y-1);dfs(x-1,y);dfs(x-1,y+1);
    dfs(x,y-1);dfs(x,y+1);
    dfs(x+1,y-1);dfs(x+1,y);dfs(x+1,y+1);
}

int main()
{
    int i,j,k;
    while(scanf("%d%d",&m,&n)){
        if(m==0 && n==0) break;
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
                scanf(" %c",&a[i][j]);
        int res=0;
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
                if(a[i][j]=='@'){
                    res++;
                    dfs(i,j);
                }
        printf("%d\n",res);
    }
    return 0;
}
