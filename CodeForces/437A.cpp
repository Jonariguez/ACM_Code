/****************
*PID:437a div2
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

struct pp{
    int len,id;
}s[44];

int cmp(pp x,pp y){
    return x.len<y.len;
}

char str[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%s",str+1)!=EOF){
        s[1].len=strlen(str+1)-2;
        s[1].id=1;
        scanf("%s",str+1);
        s[2].len=strlen(str+1)-2;
        s[2].id=2;
        scanf("%s",str+1);
        s[3].len=strlen(str+1)-2;
        s[3].id=3;
        scanf("%s",str+1);
        s[4].len=strlen(str+1)-2;
        s[4].id=4;
      //  sort(s+1,s+5,cmp);
        set<int> res;
        for(i=1;i<=4;i++){
            for(j=1;j<=4;j++){
                if(j==i) continue;
                if(s[i].len>s[j].len/2) break;
            }
            if(j>4) res.insert(i);
        }
        for(i=1;i<=4;i++){
            for(j=1;j<=4;j++){
                if(j==i) continue;
                if(s[i].len<s[j].len*2) break;
            }
            if(j>4) res.insert(i);
        }
        if(res.size()!=1)
            puts("C");
        else {
            set<int>::iterator it;
            it=res.begin();
            printf("%c\n",(*it)-1+'A');
        }
    }
    return 0;
}

