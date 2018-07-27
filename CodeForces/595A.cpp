/****************
*PID:595a div2
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
int a[maxn][maxn];

int main()
{
    int i,j,n,m,res;
    while(scanf("%d%d",&n,&m)!=EOF){
        res=0;
        for(i=0;i<n;i++){
            for(j=1;j<=m;j++){
                int x,y;
                scanf("%d%d",&x,&y);
                if(x || y) res++;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
