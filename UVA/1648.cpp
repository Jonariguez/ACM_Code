/****************
*PID:uva1648
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i,j,res,n,m,u,d;
    while(scanf("%d%d",&n,&m)!=EOF){
        scanf("%d%d",&u,&d);
        res=(u+d)-(d*n)%(d+u);
        if(res==0) res=d+u;
        for(i=1;i<m;i++){
            scanf("%d%d",&u,&d);
            int t=(u+d)-d*n%(d+u);
            if(t==0) t=d+u;
            res=min(res,t);
        }
        printf("%d\n",res);
    }
    return 0;
}
