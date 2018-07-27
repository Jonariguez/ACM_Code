/****************
*PID:629a div2
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
char a[maxn][maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        int res=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(a[i][j]=='.') continue;
                int k;
                for(k=j+1;k<=n;k++)
                    if(a[i][k]=='C') res++;
                for(k=i+1;k<=n;k++)
                    if(a[k][j]=='C') res++;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
