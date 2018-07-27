/****************
*PID:uva11520
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=12;
char str[maxn][maxn];

int main()
{
    int i,j,n,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%s",str[i]+1);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(str[i][j]!='.') continue;
                char ch;
                for(ch='A';ch<='Z';ch++){
                    int yes=1;
                    if(i>1 && str[i-1][j]==ch) yes=0;
                    if(i<n && str[i+1][j]==ch) yes=0;
                    if(j>1 && str[i][j-1]==ch) yes=0;
                    if(j<n && str[i][j+1]==ch) yes=0;
                    if(yes){
                        str[i][j]=ch;break;
                    }
                }
            }
        }
        printf("Case %d:\n",kcase++);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)
                printf("%c",str[i][j]);
            puts("");
        }
    }
    return 0;
}
