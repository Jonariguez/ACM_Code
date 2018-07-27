/****************
*PID:444a div1
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

const int maxn=500+10;
int val[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++) scanf("%d",&val[i]);
        int u,v,w;
        double res=0;
        for(i=1;i<=m;i++){
            scanf("%d%d%d",&u,&v,&w);
            res=max(res,(double)(val[v]+val[u])/w);
        }
        printf("%.10f\n",res);
    }
    return 0;
}

