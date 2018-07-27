/****************
*PID:hdu4089
*Auth:Jonariguez
*****************
���⣺��n�����Ŷӵ����ڹ����ϼ�����Ϸ��Tomato���ڵ�m����
���ڶ����еĵ�һ���ˡ���һ�������
1������ʧ�ܣ����ڶ����еȴ���һ�μ������Ϊp1)
2��ʧȥ���ӣ������У�Ȼ�����ڶ��е���󣨸���Ϊp2��
3������ɹ����뿪���У�����Ϊp3��
4��������̱����������ֹͣ��������˶��޷������ˡ�
�������̱��ʱTomato�ڶ����е�λ��<=k�ĸ���

����DP��
��dp[i][j]��ʾi�����Ŷ�,Tomato���ڵ�j��λ�ã��ﵽĿ��״̬�ĸ���(j<=i)
dp[n][m]��������
j==1:    dp[i][1]=p1*dp[i][1]+p2*dp[i][i]+p4;
2<=j<=k: dp[i][j]=p1*dp[i][j]+p2*dp[i][j-1]+p3*dp[i-1][j-1]+p4;
k<j<=i:  dp[i][j]=p1*dp[i][j]+p2*dp[i][j-1]+p3*dp[i-1][j-1];
����
j==1:    dp[i][1]=P2*dp[i][i]+P4;
2<=j<=k: dp[i][j]=P2*dp[i][j-1]+P3*dp[i-1][j-1]+P4;
k<j<=i:  dp[i][j]=P2*dp[i][j-1]+P3*dp[i-1][j-1];

���У�P2=p2/(1-p1),P3=p3/(1-p1),P4=p4/(1-p1)
��Ȼ�ǵ��ƣ�dp[i-1][j-1]������֪�ĳ�����dp[i][j]������ǰһ����ƹ����ģ�
����dp[i][1]����dp[i][i]���Ƶģ����Կ��Դ�dp[i][1]������dp[i][i]��i�
�����͵õ�������dp[i][i]=dp[i][i]*P2^i+C ����ã�dp[i][i]=C/(1-P2^i)
����C�ǿ��Ե���ά���õ���Ȼ��Ϳ���������������ˡ�
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define eps 1e-8
const int maxn=2000+10;
double dp[maxn][maxn],fact[maxn],c[maxn];

int main()
{
    int i,j,n,m,k,T,kcase=1;
    double p1,p2,p3,p4,P1,P2,P3,P4;
    while(scanf("%d%d%d%lf%lf%lf%lf",&n,&m,&k,&p1,&p2,&p3,&p4)!=EOF){
        if(fabs(p4)<=eps){
            printf("0.00000\n");continue;
        }
        P2=p2/(1-p1);
        P3=p3/(1-p1);
        P4=p4/(1-p1);
        fact[0]=1.0;
        for(i=1;i<=n;i++)
            fact[i]=fact[i-1]*P2;
        dp[1][1]=P4/(1-P2);
        for(i=2;i<=n;i++){
            c[1]=P4;
            for(j=2;j<=min(k,i);j++)
                c[j]=c[j-1]*P2+P3*dp[i-1][j-1]+P4;
            for(j=k+1;j<=i;j++)
                c[j]=c[j-1]*P2+P3*dp[i-1][j-1];
            dp[i][i]=c[i]/(1-fact[i]);
            dp[i][1]=P2*dp[i][i]+P4;
            for(j=2;j<=min(i,k);j++)
                dp[i][j]=P2*dp[i][j-1]+P3*dp[i-1][j-1]+P4;
            for(j=k+1;j<i;j++)
                dp[i][j]=P2*dp[i][j-1]+P3*dp[i-1][j-1];
        }
        printf("%.5f\n",dp[n][m]);
    }
    return 0;
}

