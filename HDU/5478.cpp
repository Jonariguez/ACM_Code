/****************
*PID:hdu5478
*Auth:Jonariguez
*****************
n=1
a^(k1+b1)+b = 0 (mod c)         ��
n=2
a^(2*k1+b1)+b^(k2+1) = 0 (mod c)    ��
��ʽͬʱ����һ����Ҳ�����������a^k1
a^k1*(a^(k1+b1)+b) = 0 (mod c)
a^(2*k1+b1) + a^k1*b = 0 (mod c)  ==> a^(2*k1+b1)+b^(k2+1) = 0 (mod c)(������ʵ�Ǣ�ʽ)
��󻯵�
a^k1 == b^k2 (mod c)
˼·��ö��a�����������a^k1,��a^(k1+b1),Ȼ���ɢ�ʽ�ó�b���ٿ�������b^k2��Ȼ���ж�
a^k1==b^k2�����������(a,b)������
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxc=200000+5;

ll Pow(ll a,ll b,ll m){
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

int main()
{
    ll i,j,res,c,k1,k2,b1;
    int kcase=1;
    while(scanf("%lld%lld%lld%lld",&c,&k1,&b1,&k2)!=EOF){
        printf("Case #%d:\n",kcase++);
        ll a,b;
        int flag=0;
        for(a=1;a<c;a++){
            ll ak1=Pow(a,k1,c);
            ll ab1=Pow(a,b1,c);
            ll ak1b1=ak1*ab1%c;
            b=(c-ak1b1)%c;
            if(b<0)
                b+=c;
            ll bk2=Pow(b,k2,c);
            if(ak1==bk2){
                printf("%lld %lld\n",a,b);
                flag=1;
            }
        }
        if(!flag)
            printf("-1\n");
    }
    return 0;
}
