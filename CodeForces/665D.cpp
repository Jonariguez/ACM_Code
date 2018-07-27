/****************
*PID:665d edu12
*Auth:Jonariguez
*****************
如果没有1的话，那么这个subset最多只能有2个
如果有意的话，就是选择所有的1和1+x是素数的x，个数为cnt[1]+1
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
#define ALL(x) (x).begin(),(x).end()
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
int cnt[maxn],is[maxn];
vector<int> p,ans,ans2;

void table(){
    int i,j;
    for(i=2;i<=2000000;i++){
        if(!is[i]){
            if((LL)i*i>2000000) continue;
            for(j=i*i;j<=2000000;j+=i) is[j]=1;
        }
    }
}

int main()
{
    int i,j,n;
    table();
    memset(cnt,0,sizeof(cnt));
    ans.clear();
    ans2.clear();
    sc(n);
    for(i=1;i<=n;i++){
        int x;
        sc(x);
        cnt[x]++;
        p.push_back(x);
    }
    sort(ALL(p));
    p.erase(unique(ALL(p)),p.end());
    int res=cnt[1];
    if(cnt[1]==0){
        int res=0,r=0;
        for(i=0;i<p.size();i++){
            int x=p[i],f=0;
            if(!is[x])
                r=x;
            for(j=i+1;j<p.size();j++)
                if(!is[x+p[j]]){
                    f=1;
                    ans.push_back(p[j]);
                    ans.push_back(p[i]);
                    break;
                }
            if(f) break;
        }
        if(ans.size()==0){
            printf("1\n%d\n",p[0]); //如果没有就输出随便一个，而不是0
            return 0;
        }
        printf("%d\n",ans.size());
        for(i=0;i<ans.size();i++)
            printf("%d ",ans[i]);
    }else {
        for(i=0;i<p.size();i++){
            if(p[i]==1 || p[i]&1) continue;
            if(!is[1+p[i]]){
                ans.push_back(p[i]);
                break;
            }
        }
        int res1=cnt[1]+ans.size();
        for(i=0;i<p.size();i++){
            if(p[i]==1) continue;
            int f=0;
            for(j=i+1;j<p.size();j++){
                if(!is[p[i]+p[j]]){
                    f=1;ans2.push_back(p[i]);
                    ans2.push_back(p[j]);
                    break;
                }
            }
            if(f) break;
        }
        if(res1>ans2.size()){
            printf("%d\n",res1);
            for(i=1;i<=cnt[1];i++)
                printf("1 ");
            for(i=0;i<ans.size();i++)
                printf("%d ",ans[i]);
        }else{
            printf("%d\n",ans2.size());
            for(i=0;i<ans2.size();i++)
                printf("%d ",ans2[i]);
        }
    }
    puts("");
    return 0;
}
