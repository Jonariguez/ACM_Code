/****************
*PID:cf573B
*Auth:Jonariguez
*****************
���ȣ�ÿ��destroyʱ�����ߵĶ���destroy����������Ƕ�
�����Ļ�����ô��i��(��1��ʼ)����ڵ�i��destroyʱ����ȫ
�ٵ���(��ʵ�����Ͻ���׼ȷ��˵�ǣ������i-1����Ҫcnt��
����Ļ�����ô��i�Ѿ�ֻ��Ҫcnt+1�ξͺ��ˣ��������ǿ���
��ǰһ���Ƴ�����ǰ�ģ�����ɨһ������ˣ�
�������i����x��block�Ļ���ÿ�����涼���ټ���һ������ô��
����Ƕ������Ļ��������destroy��Ļ������Ҫx�Ρ�
��ô�öѾ�����Ҫ���Σ��������������ߵĽ�Сֵ��
����Ҫ������Ĺ��̴���������һ�Σ����д���������һ�Σ�Ȼ��
ȡ���ߵĽ�Сֵ��Ȼ����res�������е����ֵ���Ǵ�
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;

int a[maxn],b[maxn],c[maxn];

int main()
{
    int i,j,res,n;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        a[0]=a[n+1]=0;
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(i=1;i<=n;i++)
            b[i]=min(b[i-1]+1,a[i]);
        for(i=n;i>=1;i--)
            c[i]=min(c[i+1]+1,a[i]);
        res=1;
        for(i=1;i<=n;i++)
            res=max(res,min(b[i],c[i]));
        printf("%d\n",res);
    }
    return 0;
}
