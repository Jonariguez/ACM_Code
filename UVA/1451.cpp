/*
数形结合
一开始弄错了，把所有的点都预处理了，这样得出下凸线然后
再求解是不对的(因为在选取解区间右端点时，那么该端点后面
的点是对它没有影响的，所以就可以现在立马处理)。要边处理
边求解。
主算法：从小到大枚举t，快速找到t'<=t-l,使得[t',t]斜率最大。
因为长度最小为l,所以t应该从l从开始枚举到n，那么t'的范围就是
[1,t-l]，所以每次枚举一个t时，那么就应该把t-l点加到桟中
(即"点入桟"),那么加入t-l之前就要维护下凸线。维护完下凸线
之后，直接求解解区间的左端点(枚举的t就是右端点).
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
char str[maxn];
int s[maxn],sum[maxn],stack[maxn],n,l;

//比较区间[x1,y1]和[x2,y2]的结果大小
int cmp(int x1,int y1,int x2,int y2){
    return ((ll)sum[y1]-sum[x1-1])*(y2-x2+1)-((ll)sum[y2]-sum[x2-1])*(y1-x1+1);
}

int main()
{
    int i,T,j,head,tail,t;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&l);
        scanf("%s",str+1);
        sum[0]=0;
        for(i=1;i<=n;i++)
            sum[i]=sum[i-1]+(str[i]-'0');
        int ansL=1,ansR=l;
        head=tail=0;
        for(t=l;t<=n;t++){
            //tail-head>1是保证stack中至少有两个点，如果就一个点则
            //直接加入点即可，一定满足。  "点入桟"
            //其实每次cmp时，stack中的最后一个其实是t-l，但这并不影响
            //cmp结果，更不会影响维护下凸线。之所以已经有t-l是因为上次
            //循环时有stack[tail++]=t-l+1。
            while(tail-head>1 && cmp(stack[tail-2],t-l,stack[tail-1],t-l)>=0)
                tail--;
            stack[tail++]=t-l+1;

            while(tail-head>1 && cmp(stack[head],t,stack[head+1],t)<=0)
                head++;
            int c=cmp(stack[head],t,ansL,ansR);
            if(c>0 || c==0 && t-stack[head]<ansR-ansL){
                ansL=stack[head];ansR=t;
            }
        }
        printf("%d %d\n",ansL,ansR);
    }
    return 0;
}
