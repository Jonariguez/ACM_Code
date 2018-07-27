/****************
*PID:poj2433
*Auth:Jonariguez
*****************
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
const int INF=0x3f3f3f3f;
int n,m,k;
int v[maxn];

int main()
{
    int i,j;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
        sc(v[i]);
    int res=0;
    while(true){
        int best=INF,ansl,ansr,cnt=0;
        for(i=1;i<=n;i++){
            if(v[i]<=v[i+1]) continue;
            int L=i,R=i;
            while(L>=1 && v[L-1]<=v[L]) L--;
            while(R<=n && v[R+1]<=v[R]) R++;
           // if(L>=1 || R<=n){
                int mx=max(v[L],v[R]),sum=0;
                for(j=L;j<=R;j++)
                    sum+=max(0,v[j]-mx);
                if(sum<best){
                    best=sum;
                    ansl=L;ansr=R;
                }
                cnt++;i=R;
           // }
        }
        if(cnt<=k)
            break;
        res+=best;
        int mx=max(v[ansl],v[ansr]);
        for(i=ansl;i<=ansr;i++)
            if(v[i]>mx) v[i]=mx;
    }
    printf("%d\n",res);
    return 0;
}





