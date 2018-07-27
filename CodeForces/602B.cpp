/****************
*PID:602b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
int p[maxn];

int main()
{
    int i,j,n,res,ls,lt;
    while(scanf("%d",&n)!=EOF){
        res=0;
        memset(p,0,sizeof(p));
        for(i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(p[x-1]==0 && p[x+1]==0)
                res=max(res,i);
            else if(p[x-1] && p[x+1]){
                res=max(res,i-max(p[x-1],p[x+2]));
                res=max(res,i-max(p[x+1],p[x-2]));
            }
            else if(p[x+1]==0)
                res=max(res,i-p[x-2]);
            else if(p[x-1]==0)
                res=max(res,i-p[x+2]);
            p[x]=i;
        }
        printf("%d\n",res);
    }
    return 0;
}
