/*
�ȼ�ת����
ÿ�μ���ǰi����Ҫ����work���ɣ�ע�������Ȼ���ۼ���
����ֵ��
����ȷ�Բ�������ô���ԡ�
*/
#include <stdio.h>
#include <math.h>
typedef long long ll;

ll a[100005];

int main()
{
    int i,j,n;
    ll res;
    while(scanf("%d",&n),n){
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        res=fabs(a[0]);
        ll now=a[0];
        for(i=1;i<n;i++){
            now+=a[i];
            res+=fabs(now);
        }
        printf("%lld\n",res);
    }
    return 0;
}
