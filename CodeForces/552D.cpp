/****************
*PID:552d div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=2000+10;
const int N=2005;
LL x[maxn],y[maxn];
map<LL,LL> mp;

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

LL get(LL a,LL b){
    if(a==0) return 0;
    if(b==0) return (LL)N*N+N;
    LL sa=a>=0?1:-1,sb=b>=0?1:-1;
    sa*=sb;sb=1;
    a=abs(a);b=abs(b);
    LL g=gcd(abs(a),abs(b));
    a/=g;b/=g;
    return sa*a*N+sa*b;
}

int main()
{
    int i,j;
    LL n;
    while(scanf("%I64d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%I64d%I64d",&x[i],&y[i]);
        LL res=n*(n-1)*(n-2)/6,ans=0;
        for(i=1;i<=n;i++){
            mp.clear();
            for(j=1;j<=n;j++){
                if(i==j) continue;
                LL k=get(y[i]-y[j],x[i]-x[j]);
                mp[k]++;
            }
            map<LL,LL>::iterator it=mp.begin();
            while(it!=mp.end()){
                LL t=it->second;
                if(t>=2)
                    ans+=t*(t-1)/2;
                it++;
            }
        }
        printf("%I64d\n",res-ans/3);
    }
    return 0;
}
