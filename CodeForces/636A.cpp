/****************
*PID:
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

const int maxn=1000+10;
int d[maxn][maxn];

int f(int x,int y){
   // if(x==1 && y==1) return 0;
    if(x<=0 || y<=0) return 0;
    int temp1,temp2;
    if(x>=2 && d[x-2][y+1]>=0)
        temp1=d[x-2][y+1];
    else temp1=f(x-2,y+1);
    if(y>=2 && d[x+1][y-2]>=0)
        temp2=d[x+1][y-2];
    else temp2=f(x+1,y-2);
    if(x>=2)
        d[x-2][y+1]=temp1;
    if(y>=2)
        d[x+1][y-2]=temp2;
    return max(temp1,temp2)+1;
}

int main()
{
    int i,j,n,m;
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        if(a==1 && b==1){
            puts("0");continue;
        }
        memset(d,-1,sizeof(d));
        printf("%d\n",f(a,b));
    }
    return 0;
}
