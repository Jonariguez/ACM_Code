/****************
*PID:hdu5501
*Auth:Jonariguez
*****************
dp[i][j]��ʾ����ǡ����j��ʱ����ǰi�������ߵ÷�
��Ϊ����˵����ǡ����j���ӣ��������Ҫ����j
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+5;
const int maxt=3000+5;
int dp[maxn][maxt];

struct pp{
    int a,b,c;
    double f;
}s[maxn];

int cmp(const pp &x,const pp &y){
    return x.f>y.f;
}

int main()
{
    int i,j,n,T,t;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&t);
        for(i=0;i<n;i++){
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
            s[i].f=(double)s[i].b/s[i].c;
        }
        sort(s,s+n,cmp);
      //  for(i=0;i<=t;i++) dp[0][i]=0;
        int res=0;
        for(i=0;i<n;i++){
            for(j=0;j<=t;j++){
                if(j<s[i].c)
                    dp[i+1][j]=dp[i][j];
                else
                    dp[i+1][j]=max(dp[i][j],dp[i][j-s[i].c]+s[i].a-j*s[i].b);//ע�ⲻҪ��max���dp[i][j]д��dp[i-1][j]
                /*��һ��д��
                dp[i+1][j]=dp[i][j];
                if(j>=s[i].c) dp[i+1][j]=max(dp[i+1][j],dp[i][j-s[i].c]+s[i].a-j*s[i].b);
                    */
            }
        }
        for(i=0;i<=t;i++)
            res=max(res,dp[n][i]);
        printf("%d\n",res);
    }
    return 0;
}
