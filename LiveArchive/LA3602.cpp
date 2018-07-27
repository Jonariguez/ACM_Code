/****************
*PID:la3602
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
const int ch[]={'A','C','G','T'};
char str[maxn];
int c[maxn][5];

int main()
{
    int i,j,res,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&m,&n);
        memset(c,0,sizeof(c));
        for(i=1;i<=m;i++){
            scanf("%s",str+1);
            for(j=1;j<=n;j++){
                if(str[j]=='A') c[j][0]++;
                else if(str[j]=='C') c[j][1]++;
                else if(str[j]=='G') c[j][2]++;
                else c[j][3]++;
            }
        }
        res=0;
        for(i=1;i<=n;i++){
            int maxv=0;
            maxv=max(max(c[i][0],c[i][1]),max(c[i][2],c[i][3]));
            res+=m-maxv;
            for(j=0;j<4;j++)
                if(c[i][j]==maxv){
                    printf("%c",ch[j]);break;
                }
        }
        printf("\n%d\n",res);
    }
    return 0;
}
