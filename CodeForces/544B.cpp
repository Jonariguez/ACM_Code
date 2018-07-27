/****************
*PID:544b div2
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
int a[maxn][maxn],n,k;

void cover(int i,int j){
    a[i][j]=1;a[i][j+1]=0;
}

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&k)!=EOF){
        int cnt=0;
        if(k==0){
            printf("YES\n");
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++)
                    if(a[i][j]) printf("L");
                    else printf("S");
                printf("\n");
            }
            continue;
        }
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++){
            if(i&1)
                j=1;
            else j=2;
            for(;j<=n;j+=2){
                cover(i,j);
                k--;
                if(k==0) break;
            }
            if(k==0) break;
        }
        if(k)
            printf("NO\n");
        else {
            printf("YES\n");
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++)
                    if(a[i][j]) printf("L");
                    else printf("S");
                printf("\n");
            }
        }
    }
    return 0;
}
