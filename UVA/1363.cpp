/*
P338
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

//����Ϊa������Ϊd������Ϊn�����
ll sum(ll a,ll d,ll n){
    return a*n+d*n*(n-1)/2;
}

int main()
{
    ll i,j,n,k;
    while(scanf("%lld%lld",&n,&k)!=EOF){
        ll res=0;
        i=1;
        while(i<=n){
            ll p=k/i,q=k%i;
            ll cnt=n-i;
            if(p)           //���p=0���򲻻�ִ����һ������cnt�ͻ�=n-i�����ʱ��Ҳ���ǵȲ��������������
                cnt=min(cnt,q/p);
            res+=sum(q,-p,cnt+1);
            i+=cnt+1;
        }
        printf("%lld\n",res);
    }
    return 0;
}
