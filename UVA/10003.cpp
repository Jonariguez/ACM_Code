/****************
*PID:uva10003
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=70;
const LL INF=100000000000000000;
LL a[maxn],dp[maxn][maxn];

int main()
{
    int i,j,L,n;
    while(scanf("%d",&L),L){
        scanf("%d",&n);
        a[0]=0;a[n+1]=L;
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            dp[i][i]=dp[i-1][i]=dp[i+1][i]=0;
        }
        a[0]=0;a[n+1]=L;
        for(int p=2;p<=n+1;p++){        //ע���������ѭ����Χ��p��ö�����䳤�ȣ���2��n+1
            for(i=0;i<n;i++){           //i�����
                for(j=i+p;j<=n+1;j++){      //j���յ�
                    dp[i][j]=INF;
                    for(int k=i+1;k<j;k++)      //k������i<k<j
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[j]-a[i]);
                }
            }
        }
        /* ����ö���������Ҳ���Ա�֤����ĳ����ǵ����ģ�ͬʱ�����˸��Ӷ�
        for(i=n-1;i>=0;i--){           //i�����
            for(j=i+2;j<=n+1;j++){      //j���յ�
                dp[i][j]=INF;
                for(int k=i+1;k<j;k++)      //k������i<k<j
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[j]-a[i]);
            }
        }
        */
        printf("The minimum cutting is %lld.\n",dp[0][n+1]);
    }
    return 0;
}
