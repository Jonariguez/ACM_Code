/****************
*PID:508e div2
*Auth:Jonariguez
*****************
http://blog.csdn.net/tc_to_top/article/details/43340685
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

const int maxn=1200+10;
int l[maxn],r[maxn];
char str[maxn];
struct node{
    int p,cnt;
};

stack<node> s;

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        while(!s.empty())
            s.pop();
        for(i=1;i<=n;i++)
            scanf("%d%d",&l[i],&r[i]);
        int now=1,yes=1;
        for(i=1;i<=2*n;i++){
            if(s.empty()){
                s.push((node){i,now});
                now++;
            }else {
                node u=s.top();
                if(i-u.p>r[u.cnt]){
                    yes=0;break;
                }
                if(i-u.p<l[u.cnt]){
                    s.push((node){i,now});
                    now++;
                }else {
                    str[u.p]='(';str[i]=')';
                    s.pop();
                }
            }
        }
        if(yes==0){
            puts("IMPOSSIBLE");continue;
        }
        str[2*n+1]='\0';
        puts(str+1);
    }
    return 0;
}



