/****************
*PID:la3641
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

int vis[30],cnt[30],a[30];
char str[30];

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",str+1);
        memset(cnt,0,sizeof(cnt));
        memset(vis,0,sizeof(vis));
        for(i=1;i<=26;i++)
            a[i]=(str[i]-'A')+1;
        for(i=1;i<=26;i++){
            if(vis[i]) continue;
            vis[i]=1;
            int c=1;
            j=a[i];
            while(j!=i){
                vis[j]=1;
                c++;j=a[j];
            }
            cnt[c]++;
        }
        int ok=1;
        for(i=2;i<=26;i+=2)
            if(cnt[i]%2==1)
                ok=0;
        if(ok)
            puts("Yes");
        else puts("No");
    }
    return 0;
}

