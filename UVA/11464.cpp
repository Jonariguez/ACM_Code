/****************
*PID:uva11464
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=18;
const int INF=100000000;
int n;
int a[maxn][maxn],b[maxn][maxn];

int cal(int i,int j){
    return b[i][j-1]+b[i][j+1]+b[i-1][j];
}

int solve(){
    int i,j,cnt=0,sum;
    for(i=1;i<n;i++){
        for(j=1;j<=n;j++){
            int v=cal(i,j);
            if(v&1){
                if(a[i+1][j]!=1) cnt++;
                b[i+1][j]=1;
            }else {
                if(a[i+1][j]==1) return INF;
                b[i+1][j]=0;
            }
        }
    }
    for(j=1;j<=n;j++){
        int v=cal(n,j);
        if(v&1) return INF;
    }
    return cnt;
}

int main()
{
    int i,j,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        memset(b,0,sizeof(b));
        int res=INF;
        for(i=0;i<(1<<n);i++){
            int cnt=0,flag=1;
            for(j=0;j<n;j++){
                if(((i>>j)&1)){
                    if(a[1][j+1]){      //要改这里，但是这里不能改，所以这个方案放弃
                        flag=0;break;
                    }
                    b[1][j+1]=1-a[1][j+1];
                    cnt++;
                }
                else b[1][j+1]=a[1][j+1];
            }
            if(flag==0) continue;
            cnt+=solve();
            res=min(res,cnt);
        }
        printf("Case %d: ",kcase++);
        if(res>=INF)
            printf("-1\n");
        else
            printf("%d\n",res);
    }
    return 0;
}
