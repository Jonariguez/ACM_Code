/****************
*PID:489f div2
*Auth:Jonariguez
*****************
dp[k][i][j]:��k�У���i�п����ٷ�1��1����j�п����ٷ�2��1�ķ�����
��Ϊdp[n][0][0]��kȡ0,1��תʹ�ý�ʡ�ռ䡣
ע����ת�Ƶ�ʱ��two-1����two-2ʱ��Ӧת�Ƶ���״̬oneҲӦ����Ӧ��
+1��+2��Ӧ�ô���������һ����
Ҫ���ڲ��two��ѭ�������Ż�.
���о���:
a+=b;
if(a>=mod) a-=mod;
���������һ���ԣ���ΪҪ��֤bҲӦ����[0,mod)�Ŷԣ���������
a+=(b%mod);
if(a>=mod) a-=mod;
�Ͽ��д��Ϊ��
a+=b;
if(a>=mod) a%=mod;
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=500+5;

LL dp[2][maxn][maxn];
int col[maxn];
char str[maxn];

int main()
{
    int n,m,mod,i,j;
    while(scanf("%d%d%d",&n,&m,&mod)!=EOF){
        memset(col,0,sizeof(col));
        for(i=1;i<=m;i++){
            scanf("%s",str+1);
            for(j=1;j<=n;j++)
                col[j]+=(str[j]-'0');
        }
        int one=0,two=0;
        for(i=1;i<=n;i++){
            if(col[i]==1) one++;
            else if(col[i]==0) two++;
        }
      //  printf("one=%d two=%d\n",one,two);
        memset(dp,0,sizeof(dp));
        dp[0][one][two]=1LL;
        int d=0,k;
        for(k=m+1;k<=n;k++){
            for(one=0;one<=n;one++){
                for(two=0;two<=n-k+1;two++){
                /*    if(one>=2){
                        dp[d^1][one-2][two]+=dp[d][one][two]*(one-1)*one/2;
                        dp[d^1][one-2][two]%=mod;
                    }
                    if(two>=2){
                        dp[d^1][one][two-2]+=dp[d][one][two]*(two-1)*two/2;
                        dp[d^1][one][two-2]%=mod;
                    }
                    if(one>=1 && two>=1){
                        dp[d^1][one-1][two-1]+=dp[d][one][two]*one*two;
                        dp[d^1][one-1][two-1]%=mod;
                    }*/

                    if(one>=2){         //ѡ�����п��Է�1��1��
                        dp[d^1][one-2][two]+=(dp[d][one][two]*(one-1)*one/2);
                        if(dp[d^1][one-2][two]>=mod)
                            dp[d^1][one-2][two]%=mod;
                    }
                    if(two>=2){         //ѡ�����п��Է�2��1��
                        dp[d^1][one+2][two-2]+=(dp[d][one][two]*(two-1)*two/2);
                        if(dp[d^1][one+2][two-2]>=mod)
                            dp[d^1][one+2][two-2]%=mod;
                    }
                    if(one>=1 && two>=1){   //�ֱ�ѡһ��
                        dp[d^1][one][two-1]+=(dp[d][one][two]*one*two);
                        if(dp[d^1][one][two-1]>=mod)
                            dp[d^1][one][two-1]%=mod;//if(one==2 && two==1) printf("???\n");
                      //  printf("dp[%d][one-1][two-1]=%I64d one-1=%d two-1=%d\n",k,dp[k][one-1][two-1],one-1,two-1);
                    }
                }
            }
            d^=1;
        }
        dp[d][0][0]%=mod;
        if(dp[d][0][0]<0) dp[d][0][0]+=mod;
        printf("%I64d\n",dp[d][0][0]%mod);
    }
    return 0;
}
