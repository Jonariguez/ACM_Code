/****************
*PID:hdu6012
*Auth:Jonariguez
*****************
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

const int maxn=200000+10;
const int MOD=1e9+7;

vector<int> p;

int L[maxn],R[maxn],a[maxn],b[maxn],c[maxn];
LL sum[800005];

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        p.clear();
        for(i=1;i<=n;i++){
            scanf("%d%d%d%d%d",&L[i],&R[i],&a[i],&b[i],&c[i]);
            L[i]*=2;
            p.push_back(L[i]);p.push_back(L[i]-1);
            p.push_back(L[i]+1);
            R[i]*=2;
            p.push_back(R[i]);p.push_back(R[i]+1);
            p.push_back(R[i]-1);
        }
        sort(p.begin(),p.end());
        p.erase(unique(p.begin(),p.end()),p.end());
        int N=0;
        for(i=1;i<=n;i++){
            L[i]=(upper_bound(p.begin(),p.end(),L[i])-p.begin());
            R[i]=(upper_bound(p.begin(),p.end(),R[i])-p.begin());
            N=max(N,L[i]);N=max(N,R[i]);
        }
        memset(sum,0,sizeof(sum));
        N++;
        for(i=1;i<=n;i++){
            sum[1]+=c[i];sum[L[i]]-=c[i];
            sum[L[i]]+=a[i];sum[R[i]+1]-=a[i];
            sum[R[i]+1]+=b[i];sum[N+1]-=b[i];
        }
        sum[0]=0;
        LL res=0;
        for(i=1;i<=N+1;i++){
            sum[i]+=sum[i-1];
            res=max(res,sum[i]);
        }
        printf("%lld\n",res);
    }
    return 0;
}

