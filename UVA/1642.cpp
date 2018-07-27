/*
���ɣ�˼��͵������к���
ö��ai�������[0,i-1]��i��gcdֵ�����±���㣬���
gcdֵ��ȵģ�������С���±�ֵ����Ϊgcdֵ�����log(i)
�������Ը��ӶȲ��ߡ�ÿ�α���ǰ��log(i)��gcdֵ������
���ֵ��Ϊ�𰸣���������֮����ai��ǰ���ȫ��gcdֵ
��gcd()��������ǰ���gcdֵ�����Ӷ�O(log(n)^2)
�ܸ��Ӷȣ�O(nlog(n)^2)
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
ll a[maxn];

struct pp{
    ll g;
    int id;
}s[maxn];

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int i,j,n,tot,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        ll res=0;
        int tot=0;
        for(i=0;i<n;i++){
            ll x=a[i];
            s[tot].id=i;s[tot++].g=x;
            int len=tot;
            tot=0;
            for(j=0;j<len;j++){     //����gcd��
                ll g=gcd(s[j].g,x);
                if(tot==0 || g!=s[tot-1].g){
                    s[tot].g=g;s[tot].id=s[j].id;tot++;
                }
            }
            for(j=0;j<tot;j++)      //���´�
                res=max(res,s[j].g*(i-s[j].id+1));
        }
        printf("%lld\n",res);
    }
    return 0;
}
