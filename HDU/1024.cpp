/****************
*PID:hdu1024
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=1000000+5;
int a[maxn],now[maxn],pre[maxn];
/*pre数组：假设目前处理的是第j个数，那么需要前一个
阶段的1~j-1的最大值，而此时pre[j-1]就是前一个阶段的，
使用过后，j会加1，去决策j+1，而决策j+1时会用到前一
阶段的pre[j]的值，而pre[j-1]的不会用到，就把pre[j-1]
的值更新为先阶段的pre值，以供下一个阶段使用，
即处理状态j时，pre数组：1~j-2为先阶段的值(以供下阶段使用)
而只有pre[j-1]的值是上一阶段的值(供现在更新状态j使用)
*/
/*
now[j]，表示以第j个元素为结尾的i个子段的最大和，必须包含a[j]。
pre[j]，表示前j个元素i个子段的最大和，不一定包含a[j]
*/
int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&m,&n)!=EOF){
        memset(now,0,sizeof(now));
        memset(pre,0,sizeof(pre));
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int state=0;
        for(i=1;i<=m;i++){
            state=-1999999999;
            for(j=i;j<=n;j++){
                now[j]=max(now[j-1]+a[j],pre[j-1]+a[j]);//dp[i-1][1~j-1]+a[j]);
                pre[j-1]=state;     //上一句话已经使用过了pre[j-1]，故已没用，就更新成这一阶段的状态
                state=max(state,now[j]);
            }
        }
        printf("%d\n",state);   //由now[]的定义可知，答案不一定是now[n]，而是state
    }
    return 0;
}
