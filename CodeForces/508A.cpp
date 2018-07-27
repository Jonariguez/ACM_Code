/****************
*PID:508a div2
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
int a[maxn][maxn],n,m;
int x[100005],y[100005];

int cal(int i,int j){
    return a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
}

bool check(int i,int j){
    return (cal(i,j)==4 || cal(i-1,j)==4 || cal(i,j-1)==4 || cal(i-1,j-1)==4);
}


int main()
{
    int i,j,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        memset(a,0,sizeof(a));
        for(i=1;i<=k;i++)
            scanf("%d%d",&x[i],&y[i]);
        for(i=1;i<=k;i++){
            a[x[i]][y[i]]=1;
            if(check(x[i],y[i]))
                break;
        }
        if(i<=k) printf("%d\n",i);
        else printf("0\n");
    }
    return 0;
}
