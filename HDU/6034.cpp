/****************
*PID:
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

const int maxn=100000+10;
const int MOD=1e9+7;

LL cnt[30],fact[maxn];
int hi[30],val[30];
char str[maxn];

struct node{
    int num[maxn];
    int len,id;
    bool operator < (const node &r) const {
        int L=max(len,r.len);
        for(int i=100001;i>=1;i--)
            if(num[i]!=r.num[i])
                return num[i]>r.num[i];
        return 0;
    }
}s[30];

int main()
{
    int i,j,n,kcase=0;
    fact[0]=1;
    for(i=1;i<=100000;i++)
        fact[i]=(fact[i-1]*26)%MOD;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=26;i++)
            memset(s[i].num,0,sizeof(s[i].num));
        memset(hi,0,sizeof(hi));
        for(i=1;i<=n;i++){
            scanf("%s",str+1);
            int m=strlen(str+1),t;
            if(m>1) hi[str[1]-'a'+1]=1;
            int c=0;
            for(j=m;j>=1;j--){
                t=str[j]-'a'+1;
                ++c;
                s[t].num[c]++;
                s[t].len=max(s[t].len,c);
            }
        }
        for(i=1;i<=26;i++){
            s[i].id=i;
            for(j=1;j<=100000;j++){
                s[i].num[j+1]+=s[i].num[j]/26;
                s[i].num[j]%=26;
            }
        }

        sort(s+1,s+27);

        if(hi[s[26].id]){
            int now;
            for(now=25;now>=1;now--)
                if(hi[s[now].id]==0) break;
            for(;now<=25;now++)
                swap(s[now],s[now+1]);
        }
        int base=25;
        LL res=0;
        for(i=1;i<=26;i++){
            for(j=1;j<=100000;j++)
                res=(res+((fact[j-1]*base)%MOD*s[i].num[j])%MOD)%MOD;
            base--;
        }
        cout << "Case #" << ++kcase << ": " << res << endl;
    }
    return 0;
}

