/****************
*PID:la3029
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

const int maxn=1000+5;
int mat[maxn][maxn],up[maxn][maxn],left[maxn][maxn],right[maxn][maxn];

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&m,&n);
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                char ch=getchar();
                while(ch!='F' && ch!='R') ch=getchar();
                mat[i][j]=ch=='F'?0:1;
            }
        }
        int res=0;
        for(i=1;i<=m;i++){
            int L=0,R=n+1;
            for(j=1;j<=n;j++){
                if(mat[i][j]==1){
                    up[i][j]=left[i][j]=0;L=j;
                }else {
                    up[i][j]=i==1?1:up[i-1][j]+1;
                    left[i][j]=i==1?L+1:max(left[i-1][j],L+1);
                }
            }
            for(j=n;j>=1;j--){
                if(mat[i][j]==1){
                    right[i][j]=n;R=j;
                }else {
                    right[i][j]=i==1?R-1:min(right[i-1][j],R-1);
                    res=max(res,up[i][j]*(right[i][j]-left[i][j]+1)*3);                }

            }
        }
        printf("%d\n",res);
    }
    return 0;
}
