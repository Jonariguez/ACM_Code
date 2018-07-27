/*
(x,y)�ܿ�������x,y����
a��С��ö��a��
��gcd(a,b)=gcd(a,a+b)
����ö��aʱ����y���ϰ�b������ÿ�����䳤��Ϊa��
��ÿ�������ܿ����ľ���phi[a].
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxa=2000+10;
ll phi[maxa];

void phi_table(){
    int i,j;
    memset(phi,0,sizeof(phi));
    phi[1]=1;
    for(i=2;i<=2000;i++)
        if(!phi[i])
        for(j=i;j<=2000;j+=i){
            if(!phi[j]) phi[j]=j;
            phi[j]=phi[j]/i*(i-1);
        }
}

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    ll i,j,a,b;
    ll n,k;
    phi_table();
    while(scanf("%lld%lld",&a,&b)){
        if(a==0 && b==0) break;
        n=(2*a+1)*(2*b+1)-1;
        k=0;
        for(i=1;i<=a;i++){
            ll t=b/i;       //ע��������i��a���ܻ�����
            k+=t*phi[i];
            for(j=t*i+1;j<=b;j++)
                if(gcd(j,i)==1) k++;
        }
        double res=(double)(k*4+4)/n;
        printf("%.7lf\n",res);
    }
    return 0;
}

