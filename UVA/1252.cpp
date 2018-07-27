/****************
*PID:uva1252
*Auth:Jonariguez
*****************
dp
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=128;
const int maxm=11;
int n,m,dp[(1<<maxm)][(1<<maxm)],st[maxn];
int cnt[(1<<maxm)][(1<<maxm)];
char s[maxm+5];

int dfs(int s,int a){
    if(cnt[s][a]==1) return 0;
    int k;
    int &ans=dp[s][a];
    if(ans>0) return ans;
    ans=m+1;
    for(k=0;k<m;k++){
        ans=min(ans,dfs((s|(1<<k)),(a|(1<<k))));
        ans=min(ans,dfs((s|(1<<k)),a));
    }
    ans++;
    return ans;
}

int main()
{
    int i,j;
    while(scanf("%d%d",&m,&n)){
        if(m==0 && n==0) break;
        for(i=0;i<n;i++){
            scanf("%s",s);
            st[i]=0;
            for(j=0;j<m;j++)
                if(s[j]=='1') st[i]|=(1<<j);
        }
        memset(cnt,0,sizeof(cnt));
        int mask;
        for(mask=0;mask<(1<<m);mask++){
            for(i=0;i<n;i++){
                cnt[mask][mask&st[i]]++;
            }
        }
        memset(dp,0,sizeof(dp));
        printf("%d\n",dfs(0,0));
    }
    return 0;
}
