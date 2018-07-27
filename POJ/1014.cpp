/****************
*PID:poj1014
*Auth:Jonariguez
*****************
DP
dp[i+1][j]:��ǰi�����Ӻ͵õ�jʱ��i���������ʣ����ٸ����ò����͵���-1)
(Ai:ֵ  Mi������
           Mi             dp[i][j]>=0             (��ǰi-1���Ѿ��ܼӺ͵õ�j�ˣ���ô��i������ȫʣ����)
dp[i+1][j]=-1             j<Ai || dp[i+1][j-Ai]<=0  (j<Ai������ǰi���Ӻ͵�j-Ai��������պ�����Ai����ô�͵ò���j
           dp[i+1][j-Ai]-1
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int a[7],dp[8][20002*6];
//int dp[20002*6];

int main()
{
    int i,j,sum,n=6,kcase=1;
    while(scanf("%d",&a[1])){
        sum=a[1];
        for(i=2;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i]*i;
        }
        if(sum==0) break;
        printf("Collection #%d:\n",kcase++);
        if(sum&1){
            printf("Can't be divided.\n\n");continue;
        }
        memset(dp,-1,sizeof(dp));
    /*    dp[0]=0;
        for(i=1;i<=n;i++){
            for(j=0;j<=sum/2;j++){
                if(dp[j]>=0)
                    dp[j]=a[i];
                else if(j<i || dp[j-i]<=0)
                    dp[j]=-1;
                else dp[j]=dp[j-i]-1;
            }
        }*/
    //    for(i=0;i<=n+1;i++) dp[i][0]=0;
        dp[1][0]=0;
        for(i=1;i<=n;i++){
            for(j=0;j<=sum/2;j++){
                if(dp[i][j]>=0)
                    dp[i+1][j]=a[i];
                else if(j<i || dp[i+1][j-i]<=0)
                    dp[i+1][j]=-1;
                else  dp[i+1][j]=dp[i+1][j-i]-1;    //�����dp[i+1][j-i]д����dp[i][j-i]��һֱWA��
            }
        }
      //  for(i=1;i<=7;i++)
      //      if(dp[i][sum/2]>=0) break;
        if(dp[7][sum/2]>=0)
            printf("Can be divided.\n\n");
        else printf("Can't be divided.\n\n");
    }
    return 0;
}
