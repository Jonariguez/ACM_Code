/****************
*PID:492e div2
*Auth:Jonariguez
*****************
So we can write in the array all relations between the
first and second coordinate in points for the path,
that starts in the point(0,0),i.e.y[0]=0,y[dx]=dy,...,y[((n-1)*dx)modn]=((n-1)*dy)modn.
Now we know, that all points with type(i,y[i]),where 0≤i≤n-1,
belong to the group with start point (0,0). In that case,
points with type (i, (y[i] + k)modn) belong to the group with
start point (0, k). (y[xi] + k) mod n = yi, k = (yi - y[xi] + n) mod n
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000000+10;
int c[maxn],b[maxn];

int main()
{
    int i,j,n,m,x,y,res,dx,dy;
    while(scanf("%d%d%d%d",&n,&m,&dx,&dy)!=EOF){
        x=y=c[0]=0;
        for(i=1;i<n;i++)
            c[(x=(x+dx)%n)]=(y=(y+dy)%n);
        memset(b,0,sizeof(b));
        for(i=0;i<m;i++){
            int xx,yy;
            scanf("%d%d",&xx,&yy);
            b[(yy+n-c[xx])%n]++;
        }
        int v=0;
        for(i=1;i<n;i++)
            if(b[v]<b[i])
                v=i;
        printf("0 %d\n",v);
    }
    return 0;
}
