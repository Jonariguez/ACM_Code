/****************
*PID:
*Auth:Jonariguez
*****************
ö��gcd��Ȼ���ж�ÿ����a[i]���������ӱ��gcd�ı��������ǻ���xɾ��
����ľ������ݸ���y��x����Դ�С��a[i]��gcd�����Ĳ�ֵ��ͬ����

"��Ȼ�����뵽ȥö��gcd,���ǵ�ʱ���ϵ��Ż������ǿ���ö��������
��Ϊÿ����Ϊ1����һ����һ����������һ�������ı�����"
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("d",&x,&y)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#define MP make_pair
#define X first
#define Y second
#define PI acos(-1.0)
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

const int maxn=2000000+10;
const int MOD=1e9+7;

int a[maxn];
LL cnt[maxn],sum[maxn];

int main()
{
    int i,j,n;
    LL x,y;
    scanf("%d%I64d%I64d",&n,&x,&y);
    LL k=x/y;
    int mx=0;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
        sum[a[i]]+=a[i];
        mx=max(mx,a[i]);
    }
    int N=mx;
    mx*=2;
    for(i=1;i<=mx+2;i++){
        sum[i]+=sum[i-1];
        cnt[i]+=cnt[i-1];
    }
    LL res=1000000000000000000LL;
    N=max(N,2);
    for(i=2;i<=N;i++){  //ö��gcd
        LL last=0;
        LL ans=0;
        for(j=i;;j+=i){
            LL le=max(j-k,last+1);
            LL temp=(cnt[le-1]-cnt[last])*x;
            LL temp2=((cnt[j-1]-cnt[le-1])*j-(sum[j-1]-sum[le-1]))*y;
            ans+=temp+temp2;
            if(j>N) break;
            last=(LL)j;
        }
        res=min(res,ans);
    }
    printf("%I64d\n",res);
    return 0;
}



