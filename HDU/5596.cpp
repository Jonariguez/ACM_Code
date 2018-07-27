/****************
*PID:hdu5596
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=50000+10;
int a[maxn],b[maxn],c[maxn],d[maxn];

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%d%d",&a[i],&b[i]);
        for(i=1;i<=m;i++)
            scanf("%d",&c[i]);
        sort(c+1,c+m+1);
        int pos=n,now=0;
        for(i=m;i>=1;i--){
            while(pos>0 && pos>c[i]){
                b[pos]+=now;pos--;
            }
            now++;
        }
        while(pos>0) b[pos--]+=now;
        int res=n,mark[2]={0,0};
        mark[a[n]]=b[n];
        for(i=n-1;i>=1;i--){
            if(mark[a[i]]==0) mark[a[i]]=b[i];
            if(b[i]<mark[a[i]^1]) res--;
            mark[a[i]]=max(mark[a[i]],b[i]);
        }
        printf("%d\n",res);
    }
    return 0;
}
