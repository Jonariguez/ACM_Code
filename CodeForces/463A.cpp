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

const int maxn=1000;
int a[maxn];

int main()
{
    int i,j,n,s,res;
    while(scanf("%d%d",&n,&s)!=EOF){
        res=-1;
        s*=100;
        int yes=1;
        for(i=1;i<=n;i++){
            int x,y,now;
            scanf("%d%d",&x,&y);
            x=x*100+y;
            now=x;
            if(s>=now){
                res=max(res,(s-now)%100);yes=0;
            }
        }
        if(yes)
            puts("-1");
        else
            printf("%d\n",res);
    }
    return 0;
}
