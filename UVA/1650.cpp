/****************
*ID:uva1650
*Auth:Jonariguez
*****************
dp
��dp[i][j]��ʾ����Ϊi�����У���j��β������ǰi��������������
�򵱵�i��Ҫ��Ϊ'?'ʱ���ܼ򵥣���ǰ�淽�����ܺ͡���dp[i][j]=sum(dp[i-1][k])(1<=k<i)
����i��Ҫ��Ϊ'I'ʱ��Ҳ������⡣֮ǰС��j�Ľ�β���ķ��������ۼӹ�����
��dp[i][j]=sum(dp[i-1][k])(1<=k<j)
������i��Ҫ��Ϊ'D'ʱ����Ҫ��������£�����ĳ��j��Ϊ�˱������е����ʲ��䣬
���ǰѴ��ڵ���j�����ֶ�+1�������ͱ�֤���ı�״̬�ˡ���ʵ��I����ʱ��Ҳ����������ġ�
ֻ�Ǵ������(1<=k<i)�����ǡ�D����ʱ��k��ȡֵӦ����[j,i)����Ϊ����j��ʱ������֮ǰ
���ڵ���j�����ֶ���1�ˡ�����֮ǰ��j�����j+1��һ������'D'������
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
const int MOD=1000000007;
long long dp[maxn][maxn];
char str[maxn];

int main()
{
    int i,j,n;
    while(scanf("%s",str+1)!=EOF){
        n=strlen(str+1);
        memset(dp,0LL,sizeof(dp));
        dp[1][1]=1;
        for(i=2;i<=n+1;i++){
            if(str[i-1]=='?'){
                long long sum=0;
                for(j=1;j<i;j++)
                    sum=(sum+dp[i-1][j])%MOD;
                for(j=1;j<=i;j++)
                    dp[i][j]=sum;
            }else if(str[i-1]=='I'){
                dp[i][1]=0;
                for(j=2;j<=i;j++)
                    dp[i][j]=(dp[i-1][j-1]+dp[i][j-1])%MOD;
            }else {
                dp[i][i]=0;
                for(j=i-1;j>=1;j--)
                    dp[i][j]=(dp[i][j+1]+dp[i-1][j])%MOD;
            }
        }
        long long res=0;
        for(i=1;i<=n+1;i++)
            res=(res+dp[n+1][i])%MOD;
        printf("%lld\n",res);
    }
    return 0;
}
