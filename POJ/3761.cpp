/****************
*PID:poj3761
*Auth:Jonariguez
*****************
���ȣ�����һ�� f(x)��ʾ��������λ��Ԫ��x�����Ҵ���x�ĸ�������ô��
1��f(x) = 0 (x = 1,2,...,n)�����������״̬
2��f(x) <= n - x;
3������ÿ��ð��������f(x) != 0����f(x)--;
�ȽϺ�����Ǿ���������k��ð�ݵ�������g(k)
��֪��k��ð�ݴﵽ����ĳ�Ҫ������ max f(x) == k
���� n - x <= k;�� x >= n -  kʱ��x���Է������������λ�á�
��Ԫ�ط�Ϊ[1,n-k],[n-k+1,n],��n��λ���зź���ǰn-k�����󣬺�k�����ķ���Ϊk!
����ǰn-k ��������������
����Ҫ��f(1) <= k,��1��k+1��λ�ÿɷţ��ź�1������1��λ�ö�f(2)��Ӱ�죬
2ͬ����k+1��λ�ÿɷ�...
g(k) = (k+1)^(n-k) * k!
���ս����Ϊ g(k) - g(k-1) = k! * [(k + 1)^(n - k) - k^(n - k)];
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000000+10;
const LL MOD=20100713;
LL fact[maxn];

LL quick_pow(LL a,LL b){
    a%=MOD;b%=MOD;
    LL res=1;
    while(b){
        if(b&1) res=(res*a)%MOD;
        b/=2;
        a=(a*a)%MOD;
    }
    return res;
}

int main()
{
    int T;
    LL i,j,n,k;
    fact[0]=1;
    for(i=1;i<=1000000;i++)
        fact[i]=fact[i-1]*i%MOD;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d%I64d",&n,&k);
        LL res=fact[k]*(quick_pow(k+1,n-k)-quick_pow(k,n-k));
        res%=MOD;
        if(res<0) res+=MOD;
        printf("%I64d\n",res%MOD);
    }
    return 0;
}
