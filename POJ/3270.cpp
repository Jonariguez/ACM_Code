/****************
*PID:poj3270
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

const int maxn=10000+10;
int a[maxn],be[maxn],nxt[maxn];
vector<int> p;

int get(int x){
    return (upper_bound(p.begin(),p.end(),x)-p.begin());
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        memset(be,0,sizeof(be));
        p.clear();
        for(i=1;i<=n;i++){
            sc(a[i]);
            p.push_back(a[i]);
        }
        sort(p.begin(),p.end());
        for(i=1;i<=n;i++){
            nxt[i]=get(a[i]);
          //  printf("nxt=%d ",nxt[i]);
        }
        for(i=1;i<=n;i++){
            if(be[i]==0){
                be[i]=i;
                for(j=nxt[i];j!=i;j=nxt[j]) be[j]=i;
            }
        }
        LL res=0;
        for(i=1;i<=n;i++){
            if(be[i]){
                be[i]=0;
                LL sum=a[i];
                int x=a[i],cnt=1;
                for(j=nxt[i];j!=i;j=nxt[j]){
                    sum+=a[j];be[j]=0;
                    x=min(x,a[j]);
                    cnt++;
                }
                res+=sum+(LL)x*(cnt-2);

            }
        }
        printf("%lld\n",res);
    }
    return 0;
}



