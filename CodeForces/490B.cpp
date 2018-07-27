/****************
*PID:490b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=200000+10;
int c[1000003],res[maxn],a[1000003],b[1000003];

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        int x,y,right=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=1;i<=n;i++){
            scanf("%d%d",&x,&y);
            a[x]++;a[y]++;b[y]++;
            c[x]=y;
            right=max(right,max(x,y));
        }
        x=0;y=0;
        for(i=1;i<=right;i++)
            if(a[i]==1 && b[i]==0) x=i;
        for(i=1;i<=n;i+=2){
            res[i]=x;
            x=c[x];
        }
        x=0;
        for(i=2;i<=n;i+=2){
            x=c[x];
            res[i]=x;
        }
        for(i=1;i<=n;i++)
            printf("%d ",res[i]);
        puts("");
    }
    return 0;
}

