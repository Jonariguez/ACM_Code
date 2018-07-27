/*
条件概率
首先计算出n个人，有r个人买东西的概率（设为tot）
那么在此条件下，第i个人买东西的概率就是条件概率
且等于：n个人有r个人买东西且这r个人里有第i个人的
概率设为choose[i],那么就是这种情况下第i个人买东西
的概率就是choose[i]/tot

P(A|B)=P(AB)/P(B)
choose[i] -_> P(AB)
tot       -_> P(B)

所以暴力时要记下choose的量
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int maxn=22;
double p[maxn],choose[maxn],tot;

int main()
{
    int i,j,n,r,kcase=1;
    while(scanf("%d%d",&n,&r)){
        if(n==0 && r==0) break;
        for(i=0;i<n;i++)
            scanf("%lf",&p[i]);
        tot=0;
        memset(choose,0,sizeof(choose));
        for(i=0;i<(1<<n);i++){      //枚举
            int num=0;
            for(j=i;j!=0;j>>=1) num+=j&1;
            if(num!=r) continue;            //要找恰好有r个买东西的情况
            double t=1;
            for(j=0;j<n;j++){
                if((i>>j)&1)
                    t*=p[j];        //第j个人买了，概率就是p[i]，没买就是1-p[i]
                else t*=(1-p[j]);
            }
            for(j=0;j<n;j++)
                if((i>>j)&1)
                    choose[j]+=t;    //每次要把这个概率加到第j个人买东西的概率里
            tot+=t;
        }
        printf("Case %d:\n",kcase++);
        for(i=0;i<n;++i)
            printf("%.6f\n",choose[i]/tot);
    }
    return 0;
}
