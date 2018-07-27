/****************
*PID:uva12563
*Auth:Jonariguez
*****************
DP
dp[i+1][j]:ǰi�׸�ǡ������j������ܳ����׸�
ͨ����Ŀ���ǿ����뵽�����Ǿͱ�֤��t֮ǰ����j<=t-1)
������Ȼ���ٳ�һ��678��ġ����衷,���Ե���ʱ
jѭ����t-1���ɣ�Ȼ�����j�ҵ�dp�����ֵ����
���ֵ�ж��ʱ����ʹj��������ʱ�䣩������
�����ټ���+678��Ҳͬ�����ʱ
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=55;
int dp[maxn][10000];
int a[maxn];

int main()
{
    int i,j,res,n,t,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&t);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<=t;i++)
            dp[0][i]=-1;
        dp[0][0]=0;
        for(i=0;i<n;i++){
            for(j=0;j<t;j++){
                dp[i+1][j]=dp[i][j];
                if(j>=a[i])
                    dp[i+1][j]=max(dp[i+1][j],dp[i][j-a[i]]+1);
            }
        }
        int l=0;
        res=0;
        for(i=0;i<t;i++){
            if(dp[n][i]>=res){
                res=dp[n][i];l=i;
            }
        }
        printf("Case %d: %d %d\n",kcase++,res+1,l+678);  //��1��Ϊ�ڽ���֮ǰ�������衷
    }
    return 0;
}
