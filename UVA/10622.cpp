/*
Ψһ�ֽⶨ��
��n�ֽ⣬Ȼ��������������ӵ�ָ����gcd����

һ��ʼ������������أ��뵽һ�䡰д����Ҫ������Ż���
�����븴�ӶȲ���(log(n)*log(log(n)))������û��Ҫ��ȥ�ʹ��.

����������ʵ֤�����Ż�����TLE��������

ע��n����Ϊ����������WA��2�Ρ�����
nΪ��ʱ����һ������������
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxp=100000+10;
bool vis[maxp];
vector<int> prime;

void prime_table(){
    int i,j;
    memset(vis,0,sizeof(vis));
    for(i=2;i<=100000;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(j=i*2;j<=100000;j+=i)
                vis[j]=1;
        }
    }
}

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int solve(long long n){
    int i,g,flag=0;
    for(i=0;i<prime.size();i++){
        if(n<(long long)prime[i]*prime[i]) break;
        int x=prime[i];
        if(n%x==0){
            int c=0;
            while(n%x==0){
                c++;n/=x;
            }
            if(flag==0)
                g=c;
            else g=gcd(g,c);
            flag=1;
        }
    }
    if(n>1) g=1;
    return g;
}

int main()
{
    int i;
    long long n;
    prime_table();
    while(scanf("%lld",&n),n){
        int ans=solve(n<0?-n:n);
        if(n<0)
            while(ans%2==0) ans/=2;
        printf("%d\n",ans);
    }
    return 0;
}
