/****************
*PID:
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

LL fact[20],n,k,S,num[30];
map<LL,LL> cnt[30];

//cur:index,now:count of mark,sum:as see
void dfs1(LL cur,LL now,LL sum){
    if(now>k || sum>S) return ;
    if(cur>n/2){
        cnt[now][sum]++;
        return ;
    }
    dfs1(cur+1,now,sum);
    dfs1(cur+1,now,sum+num[cur]);
    if(num[cur]<=18)
        dfs1(cur+1,now+1,sum+fact[num[cur]]);
}

LL res;

void dfs2(LL cur,LL now,LL sum){
    if(now>k || sum>S) return ;
    if(cur>n){
        for(LL i=0;i+now<=k;i++)    //注意题目是最多k个，而不是恰好k个
            if(cnt[i].count(S-sum))
                res+=cnt[i][S-sum];
        return ;
    }
    dfs2(cur+1,now,sum);
    dfs2(cur+1,now,sum+num[cur]);
    if(num[cur]<=18)
        dfs2(cur+1,now+1,sum+fact[num[cur]]);
}

int main()
{
    LL i,j;
    fact[0]=1;
    for(i=1;i<=18;i++)
        fact[i]=fact[i-1]*i;
    while(scanf("%I64d%I64d%I64d",&n,&k,&S)!=EOF){
        for(i=0;i<=k;i++) cnt[i].clear();
        for(i=1;i<=n;i++)
            scanf("%I64d",&num[i]);
        dfs1(1LL,0LL,0LL);
        res=0;
        dfs2(n/2+1,0LL,0LL);
        printf("%I64d\n",res);
    }
    return 0;
}

