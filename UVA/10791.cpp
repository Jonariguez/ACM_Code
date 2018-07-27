/*
һ��ʼ����n�ķ�Χ��ô��n���ڵ�����
����û��Ԥ���� ��������������ĳ����
�����Ӻ��ܵ���������
��sqrt(n)��Χ���Գ���������n��Ϊ1����ô
��ʱn���Ǵ���sqrt(n)���Ǹ�������

����n�����������ֻ��һ����
*/
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;


ll solve(ll n){
    ll i;           //����һ��ʼi��int��TLE������
    ll res=0;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            ll sum=1;
            while(n%i==0){
                sum*=i;
                n/=i;
            }
            res+=sum;
        }
    }
    if(n>1) res+=n;
    return res;
}


int main()
{
    int i,kcase=1;
    ll n,res;
    while(scanf("%lld",&n)){
        if(n==0) break;
        printf("Case %d: ",kcase++);
        if(n==1){
            printf("2\n");continue;
        }
        res=solve(n);
        if(res==n)
            printf("%lld\n",n+1);
        else
            printf("%lld\n",res);
    }
    return 0;
}
