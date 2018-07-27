/****************
*PID:433C div2
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

const int maxn=100000+10;
int a[maxn],b[maxn];
vector<int> c[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++) c[i].clear();
        LL ans=0;
        for(i=1;i<=m;i++){
            sc(a[i]);
            if(i!=1) ans+=abs(a[i]-a[i-1]);
        }
        for(i=1;i<=m;i++){
            if(i>1 && a[i]!=a[i-1])
                c[a[i]].push_back(a[i-1]);
            if(i<m && a[i]!=a[i+1])
                c[a[i]].push_back(a[i+1]);
        }
        LL mx=0;
        for(i=1;i<=n;i++){
            if(c[i].size()==0) continue;
            int x=0;
            LL tot=0;   //本来的abs差值。
            for(j=0;j<c[i].size();j++){
                b[++x]=c[i][j];
                tot+=abs(c[i][j]-i);
            }
            sort(b+1,b+x+1);
            int temp=b[x/2+1];
            LL sum=0;   //取完中位数之后的差值。
            for(j=1;j<=x;j++) sum+=abs(b[j]-temp);
            mx=max(mx,tot-sum); //取减少了的最大值
        }
        printf("%I64d\n",ans-mx);
    }
    return 0;
}



