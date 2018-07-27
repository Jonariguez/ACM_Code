/****************
*PID:FZUOJ2020
*Auth:Jonariguez
*****************
��ϣ�Lucas����:
A��B�ǷǸ�������p��������ABд��p���ƣ�A=a[n]a[n-1]...a[0]��B=b[n]b[n-1]...b[0]��
�������C(A,B) = C(a[n],b[n])*C(a[n-1],b[n-1])*...*C(a[0],b[0]) mod p.
����Lucas(n,m,p)=c(n%p,m%p)*Lucas(n/p,m/p,p).

ֻҪm��p����һ����С�����Ա�֤����ʱ��<1e5���Ұɣ���
��ΪҪôm�����С��Ҫômod p֮��С��
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef __int64 ll;

ll quick_pow(ll a,ll b,ll m){
    a%=m;
    ll res=1;
    while(b){
        if(b&1)
            res=(res*a)%m;
        b/=2;
        a=(a*a)%m;
    }
    return res;
}
/*
���ݷ���С����
��֪(a,p)=1��a^(p-1) �� 1 (mod p),���� a*a^(p-2) �� 1 (mod p)��
��aģp����Ԫinv��a^(p-2)
*/
ll Comb(ll n,ll m,ll p){
    if(m>n) return 0;
    if(m==n) return 1;
    if(m>n-m) m=n-m;
    ll res=1,i,a=1,b=1;
    for(i=0;i<m;i++){
        a=(a*(n-i))%p;  //C(n,m)=n!/(m!*(n-m)!) Ȼ��Լȥ��������֮��a�Ƿ��ӣ�b�Ƿ�ĸ����ϸ��һ�¡�
        b=(b*(i+1))%p;
    }
    ll inv=quick_pow(b,p-2,p);  //���ĸb����Ԫ
    res=(a*inv)%p;
    return res;
}

ll Lucas(ll n,ll m,ll p){
    if(m==0) return 1;
    return Comb(n%p,m%p,p)*Lucas(n/p,m/p,p)%p;
}

int main()
{
    int i,j,T;
    ll n,m,p;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d%I64d%I64d",&n,&m,&p);
        printf("%I64d\n",Lucas(n,m,p));
    }
    return 0;
}
