/****************
*PID:486b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
int n,m;
int a[maxn][maxn],b[maxn][maxn];

int main()
{
    int i,j,res;
    while(scanf("%d%d",&m,&n)!=EOF){
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&b[i][j]);
                a[i][j]=1;
            }
        }
        int v,k,yes=1;
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if(b[i][j]==0){
                    for(k=1;k<=n;k++)
                        a[i][k]=0;
                    for(k=1;k<=m;k++)
                        a[k][j]=0;
                }
            }
        }
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if(b[i][j]){
                    int sum=0;
                    for(k=1;k<=n;k++) sum+=a[i][k];
                    for(k=1;k<=m;k++) sum+=a[k][j];
                    if(sum==0){
                        yes=0;break;
                    }
                }
            }
        }
        if(yes==0)
            puts("NO");
        else {
            puts("YES");
            for(i=1;i<=m;i++){
                for(j=1;j<=n;j++)   printf("%d ",a[i][j]);
                puts("");
            }
        }
    }
    return 0;
}
