/****************
*PID:uva10795
*Auth:Jonariguez
*****************
°Ñº¬ÓÐ
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=60+4;
int start[maxn],finish[maxn];

LL f(int *P,int now,int goal){
    if(now==0) return 0;
    if(P[now]==goal) return f(P,now-1,goal);
    return f(P,now-1,6-P[now]-goal)+(1LL<<(now-1))-1+1;
}

int main()
{
    int i,j,n,kcase=1;
    while(scanf("%d",&n),n){
        for(i=1;i<=n;i++)
            scanf("%d",&start[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&finish[i]);
        int k=n;
        while(k>=1 && start[k]==finish[k]) k--;
        LL res=0;
        if(k>=1){
            int temp=6-start[k]-finish[k];
            res=f(start,k-1,temp)+f(finish,k-1,temp)+1;
        }
        printf("Case %d: %lld\n",kcase++,res);
    }
    return 0;
}
