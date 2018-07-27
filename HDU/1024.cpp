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
/*pre���飺����Ŀǰ������ǵ�j��������ô��Ҫǰһ��
�׶ε�1~j-1�����ֵ������ʱpre[j-1]����ǰһ���׶εģ�
ʹ�ù���j���1��ȥ����j+1��������j+1ʱ���õ�ǰһ
�׶ε�pre[j]��ֵ����pre[j-1]�Ĳ����õ����Ͱ�pre[j-1]
��ֵ����Ϊ�Ƚ׶ε�preֵ���Թ���һ���׶�ʹ�ã�
������״̬jʱ��pre���飺1~j-2Ϊ�Ƚ׶ε�ֵ(�Թ��½׶�ʹ��)
��ֻ��pre[j-1]��ֵ����һ�׶ε�ֵ(�����ڸ���״̬jʹ��)
*/
/*
now[j]����ʾ�Ե�j��Ԫ��Ϊ��β��i���Ӷε����ͣ��������a[j]��
pre[j]����ʾǰj��Ԫ��i���Ӷε����ͣ���һ������a[j]
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
                pre[j-1]=state;     //��һ�仰�Ѿ�ʹ�ù���pre[j-1]������û�ã��͸��³���һ�׶ε�״̬
                state=max(state,now[j]);
            }
        }
        printf("%d\n",state);   //��now[]�Ķ����֪���𰸲�һ����now[n]������state
    }
    return 0;
}
