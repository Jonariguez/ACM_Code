/****************
*PID:d
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
int a[maxn][maxn];
int dx[8]={2,1,-1,-2,-1,-2,1,2};
int dy[8]={1,2,-2,-1,2,1,-2,-1};
vector<int> K,Q,P;

int main()
{
    int i,j,n,m,kcase=1;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0 && m==0) break;
        memset(a,0,sizeof(a));
        K.clear();P.clear();Q.clear();
        int k;
        scanf("%d",&k);
        int x,y;
        while(k--){
            scanf("%d%d",&x,&y);
            Q.push_back(x);Q.push_back(y);
        }
        scanf("%d",&k);
        while(k--){
            scanf("%d%d",&x,&y);
            a[x][y]=2;
            K.push_back(x);
            K.push_back(y);
        }
        scanf("%d",&k);
        while(k--){
            scanf("%d%d",&x,&y);
            a[x][y]=3;
        }
        for(i=0;i<Q.size();i+=2){
            x=Q[i];y=Q[i+1];
            a[x][y]=1;
            for(j=y-1;j>=1;j--){
                if(a[x][j]==3 || a[x][j]==2) break;
                a[x][j]=1;
            }
            for(j=y+1;j<=m;j++){
                if(a[x][j]==3 || a[x][j]==2) break;
                a[x][j]=1;
            }
            for(j=x-1;j>=1;j--){
                if(a[j][y]==3 || a[j][y]==2) break;
                a[j][y]=1;
            }
            for(j=x+1;j<=n;j++){
                if(a[j][y]==3 || a[j][y]==2) break;
                a[j][y]=1;
            }
            for(k=x-1,j=y-1;k>=1 && j>=1;k--,j--){
                if(a[k][j]==2 || a[k][j]==3) break;
                a[k][j]=1;
            }
            for(k=x-1,j=y+1;k>=1 && j<=m;k--,j++){
                if(a[k][j]==2 || a[k][j]==3) break;
                a[k][j]=1;
            }
            for(k=x+1,j=y+1;k<=n && j<=m;k++,j++){
                if(a[k][j]==2 || a[k][j]==3) break;
                a[k][j]=1;
            }
            for(k=x+1,j=y-1;k<=n && j>=1;k++,j--){
                if(a[k][j]==2 || a[k][j]==3) break;
                a[k][j]=1;
            }
        }
        for(j=0;j<K.size();j+=2){
            x=K[j];y=K[j+1];
            for(i=0;i<8;i++){
                    int xx=x+dx[i],yy=y+dy[i];
                    if(xx<1 || xx>n || yy<1 || yy>m) continue;
                    a[xx][yy]=2;
                }
        }
        int res=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(a[i][j]==0)
                    res++;
            }
        }
        printf("Board %d has %d safe squares.\n",kcase++,res);
    }
    return 0;
}

