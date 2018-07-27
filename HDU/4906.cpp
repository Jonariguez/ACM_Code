/****************
*PID:hdu4906
*Auth:Jonariguez
*****************
״ѹdp
dp[i] = j;����iת��Ϊ������,1��ʾ������ø�λ,0��ʾ������á�j ��ʾ ������
����˵:dp[5] = 3. ��Ϊ5�Ķ�������1 0 1.���Ժ�Ϊ1�Ĵ���3��.��Ϊ3�Ĵ�Ҳ��3����
��Ϊ 2 �Ĵ���������Ϊ5ת��Ϊ�����ƺ󣬵ڶ�λ��0.
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

const int maxn=21;
const int MOD=1e9+7;
LL dp[2][1<<maxn];

int main()
{
    int i,j,n,m,L,k,T;
    sc(T);
    while(T--){
        scanf("%d%d%d",&n,&k,&L);
        memset(dp,0,sizeof(dp));
        int ALL=(1<<k)-1;
        int pre=0,now=1;
        int mx=min(L,k);
        dp[pre][0]=1;
        for(i=0;i<n;i++){
            memset(dp[now],0,sizeof(dp[now]));
            for(int S=0;S<=ALL;S++){
                if(dp[pre][S]==0) continue;
                int cnt=1;  //���L<=k,aiֻҪȡ0ʱ�Ż��״̬ת��û��Ӱ��
                if(L>k)
                    cnt+=L-k;   //���L>k,��ai����ȡ0��״̬ת��û��Ӱ�죬ȡ[k+1,L]Ҳû��Ӱ��
                dp[now][S]=(dp[now][S]+dp[pre][S]*cnt%MOD)%MOD;
                for(j=1;j<=mx;j++){ //aiȥ[1,min(L,k)]�����j��״̬��ת��
                    //S| ˵��S��״̬��������ᱣ��
                    //|(S<<j) ˵����S�������������j�õ�����������
                    //|(1<<(j-1)) ��Ȼ����j�ˣ�˵���϶��ٲ���j�������
                    //&ALL ������(S<<j)����ô����j֮�󣬶�����Щ����k������Ȼ�Ͷ����ˣ�����ͨ��&ALL����֤st��
                    //������[0,1<<k)�ڡ�
                    int st=((S|(S<<j)|(1<<(j-1)))&ALL);
                    dp[now][st]=(dp[now][st]+dp[pre][S])%MOD;
                }
            }
            swap(now,pre);
        }
        LL res=0;
        for(i=1;i<=ALL;i++)
            if(i&(1<<(k-1))){
                res+=dp[pre][i];
                res%=MOD;
            }
        if(res<0)
            res+=MOD;
        printf("%I64d\n",res);
    }
    return 0;
}




