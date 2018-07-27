#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=500+10;
int n,m;
int a[maxn][maxn],b[maxn];

int main()
{
    int i,j,k,q,s,t;
    scanf("%d%d%d",&n,&m,&q);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    memset(b,0,sizeof(b));
    for(i=1;i<=n;i++){
        s=t=1;
        while(t<=m){
            while(t<=m && a[i][t]) t++;
            while(a[i][s]==0) s++;
            b[i]=max(b[i],t-s);
            t++;
            s=t;
        }
    }
    int x,y;
    while(q--){
        scanf("%d%d",&x,&y);
        a[x][y]=1-a[x][y];
        s=t=1;b[x]=0;
        while(t<=m){
            while(t<=m && a[x][t]) t++;
            while(a[x][s]==0) s++;
            b[x]=max(b[x],t-s);
            t++;
            s=t;
        }
        int res=0;
        for(i=1;i<=n;i++)
            res=max(res,b[i]);
        printf("%d\n",res);
    }
    return 0;
}
