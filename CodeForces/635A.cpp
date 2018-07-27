/****************
*PID:635a
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
int a[maxn][maxn],RR,CC,n,k;

int main()
{
    int i,j;
    while(scanf("%d%d%d%d",&RR,&CC,&n,&k)!=EOF){
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x][y]=1;
        }
        int res=0;
        for(int r=1;r<=RR;r++){
            for(int c=1;c<=CC;c++){
                for(int R=r;R<=RR;R++){
                    for(int C=c;C<=CC;C++){
                        int cnt=0;
                        for(i=r;i<=R;i++){
                            for(j=c;j<=C;j++){
                                if(a[i][j]) cnt++;
                            }
                        }
                        if(cnt>=k) res++;
                    }
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
