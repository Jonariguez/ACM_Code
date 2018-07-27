/****************
*PID:hdu4433
*Auth:Jonariguez
*****************
dp[i][j][k]:ǰiλok����i+1λ����ת����j�Σ���i+2λ����ת��k�ε�min
�𰸣�dp[n][0][0]
���߷�Ϊ���֣�������ת��������ת��
��i-1λ��״̬dp[i][j][k],��dp[i+1][][]ת�ƣ����iλӦ��ok����ô��Ϊ״̬
dp[i][j][k]����i-1λʱ���ѵ�iλ(��i-1����һλi-1+1=i)����ת����j�Σ����ʱ
�Ͱ�a[i]�����a[i]+j,���ݾ��ߢ�����ת��b[i]����Ӧ��תcnt=(b[i]-(a[i]+j)+20)%10�Ρ�
��Ϊ��iλת��cnt�Σ���ô��i+1λת���Ĵ���pӦ��<=cnt,ͬ���i+2λ��ת������q<=p,
��ȥö��p��q��ö��pʱ����i+1λʱ����Ϊ����dp[i][j][k]ʱ��i-1+2=i+1λ������ת����
k�Σ�����������ת��p��ʱ����ô��״̬Ӧ��(k+p)%10�Ρ�  q����Ӱ�졣
���ߢ�ͬ��
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
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=1000+10;
const int INF=1e9;
char str[maxn],str2[maxn];
int a[maxn],b[maxn],dp[maxn][10][10];

int main()
{
    int i,j,k,n;
    while(scanf("%s%s",str,str2)!=EOF){
        n=strlen(str);
        for(i=0;i<n;i++){
            a[i]=str[i]-'0';
            b[i]=str2[i]-'0';
        }
        for(i=0;i<=n;i++)
            for(j=0;j<10;j++)
                for(k=0;k<10;k++) dp[i][j][k]=INF;
        dp[0][0][0]=0;
        for(i=0;i<n;i++){
            for(j=0;j<10;j++){
                for(k=0;k<10;k++){
                    if(dp[i][j][k]==INF) continue;
                    int cnt=(b[i]-(a[i]+j)+20)%10;  //����һ��λi��ʱ�����ڴ�����λi-1ʱ��iλ����j�Σ�����a[i]+j
                    for(int p=0;p<=cnt;p++){
                        for(int q=0;q<=p;q++){
                            dp[i+1][(k+p)%10][q]=min(dp[i+1][(k+p)%10][q],dp[i][j][k]+cnt);
                        }
                    }
                    cnt=(10-cnt)%10;
                    for(int p=0;p<=cnt;p++){
                        for(int q=0;q<=p;q++){
                            dp[i+1][(k-p+10)%10][(10-q)%10]=min(dp[i+1][(k-p+10)%10][(10-q)%10],dp[i][j][k]+cnt);
                        }
                    }
                }
            }
        }
        printf("%d\n",dp[n][0][0]);
    }
    return 0;
}




