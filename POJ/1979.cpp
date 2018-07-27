/****************
*PID:poj1979
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=25;
int a[maxn][maxn];
int si,sj,w,h,res;

void dfs(int i,int j){
    if(i<1 || i>h || j<1 || j>w || a[i][j]) return ;
    a[i][j]=1;
    res++;
    dfs(i-1,j);
    dfs(i+1,j);
    dfs(i,j-1);
    dfs(i,j+1);
}

int main()
{
    int i,j;
    while(scanf("%d%d",&w,&h)){
        if(w==0 && h==0) break;
        char c;
        memset(a,0,sizeof(a));
        for(i=1;i<=h;i++){
            for(j=1;j<=w;j++){
                scanf(" %c",&c);
                if(c=='#')
                    a[i][j]=1;
                else if(c=='@'){
                    si=i;sj=j;
                }
            }
        }
        res=0;
        dfs(si,sj);
        printf("%d\n",res);
    }
    return 0;
}
