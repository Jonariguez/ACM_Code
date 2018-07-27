/****************
*PID:510a div2
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

const int maxn=100000+10;

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++){
            if(i&1){
                for(j=1;j<=m;j++)
                    printf("#");
            }else {
                if(i%4!=0){
                    for(j=1;j<m;j++)
                        printf(".");
                    printf("#");
                }else {
                    printf("#");
                    for(j=1;j<m;j++)
                        printf(".");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
