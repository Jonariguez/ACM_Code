/****************
*PID:hdu3047
*Auth:Jonariguez
*****************
和座位是环状的没有关系，没有影响
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=50000+10;
LL par[maxn],rel[maxn],n,m;

void Init(){
    for(LL i=0;i<=n;i++){
        par[i]=i;rel[i]=0;
    }
}

LL find(LL x){
    if(par[x]==x) return x;
    LL y=find(par[x]);
    rel[x]+=rel[par[x]];
    return par[x]=y;
}

int main()
{
    LL i,j,res;
    while(scanf("%I64d%I64d",&n,&m)!=EOF){
        Init();
        res=0;
        for(i=1;i<=m;i++){
            LL a,b,x;
            scanf("%I64d%I64d%I64d",&a,&b,&x);
            LL pa=find(a),pb=find(b);
            if(pa!=pb){
                par[pb]=pa;
                rel[pb]=rel[a]-rel[b]+x;
            }else {
                if(rel[b]-rel[a]!=x) res++;
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}
