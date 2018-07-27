/****************
*PID:hdu4825
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

const int maxn=1000000+10;
int n,m;
LL a[maxn];

typedef struct Trie{
    LL chi[maxn*4][2],val[maxn*4],Size;
    void Init(){
        Size=1;memset(chi[0],0,sizeof(chi[0]));
    }
    void Insert(LL z){
        LL i,u=0;
        for(i=32;i>=0;i--){
            LL v=(z&(1LL<<i))>0?1:0;
            if(!chi[u][v]){
                memset(chi[Size],0,sizeof(chi[Size]));
                val[Size]=0;
                chi[u][v]=Size++;
            }
            u=chi[u][v];
        }
        val[u]=z;
    }
    LL ask(LL z){
        LL i,u=0;
        for(i=32;i>=0;i--){
            LL v=(z&(1LL<<i))>0?1:0;
            if(chi[u][v^1])
                u=chi[u][v^1];
            else u=chi[u][v];
        }
        return val[u];
    }
}Trie;

Trie trie;

int main()
{
    int i,j,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        printf("Case #%d:\n",kcase++);
        scanf("%d%d",&n,&m);
        trie.Init();
        for(i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
            trie.Insert(a[i]);
        }
        while(m--){
            LL v;
            scanf("%I64d",&v);
            printf("%I64d\n",trie.ask(v));
        }
    }
    return 0;
}
