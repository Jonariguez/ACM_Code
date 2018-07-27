/****************
*PID:626d div2
*Auth:Jonariguez
*****************
�ص����ڲ�ֵ�ϣ���ֵ��಻��5000����Ԥ�������ֵ
����¼ÿ�ֲ�ֵ�ĸ�����ÿ�ֵ������Ϊm�֣���C(n,2)��
����������Ϣ��������ֺ��ֵ�ĸ��ʣ���
p[d[i]+d[j]]=P(��һ�ֲ�ֵΪd[i])*P(�ڶ��ֲ�ֵΪd[j])
Ȼ�����p�����ǰ׺�ͣ�ö�ٵ����ֵ����(��ʵ���ǲ�ֵ)
D��Ȼ���ۼ�P(�����ֲ�ֵΪD)*P(ǰ���ֲ�ֵΪ2,3..D-1�ĸ��ʣ����Ǵ𰸡�
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=2000+5;
const int maxv=5000+5;
int a[maxn],cnt[maxv],cntc[maxv],d[maxn*maxn],n;
double sum[maxv],p[maxv];

int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        memset(cnt,0,sizeof(cnt));
        int tot=0;
        for(i=1;i<=n;i++)
            for(j=1;j<i;j++){
                d[tot]=a[i]-a[j];
                cnt[d[tot]]++;
                tot++;
            }
        sort(d,d+tot);
        tot=unique(d,d+tot)-d;
      //  for(i=0;i<tot;i++)
      //      printf("%d\n",d[i]);
        int m=(n-1)*n/2;
        memset(p,0,sizeof(p));
        for(i=0;i<tot;i++){
            for(j=0;j<tot;j++){
                if(d[j]+d[i]>=d[tot-1]) break;
                p[d[j]+d[i]]+=(double)cnt[d[j]]/m*(double)cnt[d[i]]/m;
            }
        }
     //   for(i=0;i<10;i++)
     //       printf("%d %.2f\n",i,p[i]);
        sum[0]=0.0;
        for(i=1;i<=5000;i++) sum[i]=sum[i-1]+p[i];
        double res=0;
        for(i=0;i<tot;i++)
            res+=(double)cnt[d[i]]/m*sum[d[i]-1];
        printf("%.7f\n",res);
    }
    return 0;
}

