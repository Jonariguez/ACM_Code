/****************
*PID:444a div1
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

const int maxn=100+10;
int a[maxn][maxn],n,m;
char str[maxn][maxn];

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%s",str[i]+1);
        for(i=1;i<=n;++i){
            for(j=1;j<=m;j++){
                if(str[i][j]=='-') printf("-");
                else if((i+j)&1)
                    printf("W");
                else printf("B");
            }
            puts("");
        }
    }
    return 0;
}
