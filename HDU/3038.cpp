/****************
*PID:hdu3038
*Auth:Jonariguez
*****************
a到b之间和为s，可看做b比a-1大s（前缀和）
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=200000+6;

int par[maxn],under[maxn],n;

void Init(){
    for(int i=0;i<=n;i++){
        par[i]=-1;under[i]=0;
    }
}

int find(int x){
    if(par[x]==-1) return x;
    int y=find(par[x]);
    under[x]+=under[par[x]];
    return par[x]=y;
}

int main()
{
    int i,j,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        Init();
        int res=0;
        while(m--){
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            a--;
            int pa=find(a),pb=find(b);
            if(pa!=pb){
                par[pb]=pa;
                under[pb]=under[a]-under[b]+w;  //b-pb=un[b],a-pa=un[a],b-a=w联立.
            }else {
                if(under[b]-under[a]!=w) res++;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
