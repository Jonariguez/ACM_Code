/****************
*PID:hdu1213
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
int par[maxn];

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++) par[i]=i;
        int res=n;
        while(m--){
            int a,b;
            scanf("%d%d",&a,&b);
            int pa=find(a),pb=find(b);
            if(pa!=pb){
                res--;par[pa]=pb;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}

