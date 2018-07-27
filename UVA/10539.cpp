/*
�����ԣ������飬��f(n)��ʾ��1��n���������������ĸ�����
��ô�𰸾���f(U)-f(L-1)
�����ԣ�������Ҫ���������Ǵ�10^12�ǲ����ܵġ�
������ϸ����Ҫ���Ǳ�������������ֻ��һ�������ӣ�
Ҳ�����������ĳ������p��p^2,p^3...p^k�� ����СҲӦ��
��p^2����Ϊp�����ǲ����ϵģ����Դ��ķ�Χ������
sqrt(U)=10^6��
����f(n)ʱ��ö������p�������[1,n]��p���������ж��ٸ�
�ۼӼ��ɡ�

��p^2,p^3...p^kת��������������ʽ��
p^2 (p^2)*p (p^2)*p^2 (p^2)*p^3 .. (p^2)*p^(k-2)

������t=n/(p^2),��ô��t�ķ�Χ��ö��k���ɡ�
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=1000000;
vector<long long> prime;
bool vis[maxn+5];

void prime_table(){
    long long i,j;
    memset(vis,0,sizeof(vis));
    for(i=2;i<=maxn;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(j=i*2;j<=maxn;j+=i)
                vis[j]=1;
        }
    }
}

long long cal(long long n){
    long long res=0;
    for(int i=0;i<prime.size();i++){
        if(n<prime[i]*prime[i]) break;
        long long t=n/(prime[i]*prime[i]);
        long long k=1;
        while(t>=k){
            res++;
            k*=prime[i];
        }
    }
    return res;
}

int main()
{
    int T;
    long long L,U;
    prime_table();
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&L,&U);
        printf("%lld\n",cal(U)-cal(L-1));
    }
    return 0;
}
