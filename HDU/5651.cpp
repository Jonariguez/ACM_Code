/****************
*PID:hdu5651
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
typedef long long Ll;
const int maxn=1000+10;
const int MOD=1e9+7;
Ll quick_pow(Ll a,Ll b){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

char str[maxn];
int vis[30];
LL fact[maxn];

int main()
{
    int i,j,n,m,T;
    fact[0]=1;
    for(i=1;i<=1001;i++)
        fact[i]=(fact[i-1]*i)%MOD;  //预处理阶乘
    scanf("%d",&T);
    while(T--){
        scanf("%s",str+1);
        n=strlen(str+1);
        int f=0;
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++)
            vis[str[i]-'a']++;
        int cnt1=0;
        for(i=0;i<26;i++){
            if(vis[i]) cnt1++;
            if(vis[i]&1){
                if(f) break;
                f=i+1;
            }
        }
        if(i<26){
            puts("0");
            continue;
        }
        if(cnt1==1){
            puts("1");continue;
        }
        LL res=1;
        int cnt=0;
        for(i=0;i<26;i++){
            if(vis[i]){
                cnt+=(vis[i]/2);
            }
        }
        res=fact[cnt];
        for(i=0;i<26;i++){
            if(vis[i]){
                LL inv=quick_pow(fact[vis[i]/2],MOD-2); //由费马小定理求出逆元
                res=(res*inv)%MOD;
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}

