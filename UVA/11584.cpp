/****************
*PID:uva11584
*Auth:Jonariguez
*****************
DP
dp[i]:1~i�ܻ��ֳɵ����ٵĻ��Ĵ�����
״̬ת�ƣ�dp[i]={min(dp[j]+1)|str[j+1...i]�ǻ���}
O(n^2)Ԥ�����str[i..j]�Ƿ��ǻ���is[i][j]
״̬O(n) ����O(n)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
char str[maxn];
bool is[maxn][maxn];
int dp[maxn];

int main()
{
    int i,j,T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%s",str+1);
        n=strlen(str+1);
        memset(is,0,sizeof(is));
        for(i=1;i<=n;i++){
            int s,t;
            is[i][i]=1;
            if(i!=1){
                s=i-1;t=i;
                while(s>=1 && t<=n && str[s]==str[t]){
                    is[s][t]=1;s--;t++;
                }
            }
            if(i!=n){
                s=i;t=i+1;
                while(s>=1 && t<=n && str[s]==str[t]){
                    is[s][t]=1;s--;t++;
                }
            }
            s=i-1;t=i+1;
            while(s>=1 && t<=n && str[s]==str[t]){
                is[s][t]=1;s--;t++;
            }
        }
        dp[0]=0;
        for(i=1;i<=n;i++){
            dp[i]=i;
            for(j=0;j<i;j++)
                if(is[j+1][i])
                    dp[i]=min(dp[i],dp[j]+1);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
