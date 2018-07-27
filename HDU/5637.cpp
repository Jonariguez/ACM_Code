/****************
*PID:hdu5637
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=16;
const int maxv=400000+5;
const LL MOD=1e9+7;
int a[maxn],d[maxv],n,m;

void bfs(){
    memset(d,-1,sizeof(d));
    d[0]=0;
    int i;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int u=que.front();que.pop();
        for(i=0;i<=17;i++){
            int t=(u^(1<<i));
            if(d[t]<0){
                d[t]=d[u]+1;que.push(t);
            }
        }
        for(i=1;i<=n;i++){
            int t=(u^a[i]);
            if(d[t]<0){
                d[t]=d[u]+1;que.push(t);
            }
        }//puts("???");
    }
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);//puts("???");
        bfs();
        LL res=0;
        int s,t;
        for(i=1;i<=m;i++){
            scanf("%d%d",&s,&t);
            res=(res+(LL)i*d[s^t])%MOD;
        }
        printf("%lld\n",res);
    }
    return 0;
}
