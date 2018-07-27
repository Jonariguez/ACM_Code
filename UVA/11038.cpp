/****************
*PID:uva11038
*Auth:Jonariguez
*****************
n�ĵ�iλΪ0=n��ߵ�������λ��*10^(i-1)
n�ĵ�iλ��Ϊ0 =��n��ߵ���-1��*10^(i-1)+��iλ�ұߵ���+1��
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

LL fact[12];

LL cal(LL n){
    if(n<0) return 0;
    LL left=n,right=0,bit=1,res=0;
    while(left>=10){
        int now=left%10;left/=10;
        if(now)
            res+=left*bit;
        else res+=(left-1)*bit+right+1; //֮����-1����Ϊnow=0ʱ�������ǲ�������ȡ0~9�ģ�֮����+1����Ϊ�ұߵ�����0..0~right,
        right+=now*bit;
        bit*=10;
    }
    return res;
}

int main()
{
    LL i,j,n,m;
    fact[0]=1;
    for(i=1;i<=10;i++) fact[i]=fact[i-1]*10;
    while(scanf("%lld%lld",&m,&n)){
        if(m<0) break;
        LL res=cal(n)-cal(m-1);
        if(m==0) res++;
        printf("%lld\n",res);
    }
    return 0;
}
