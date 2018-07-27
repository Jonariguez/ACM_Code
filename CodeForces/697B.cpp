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

const int maxn=200000+10;
const int MOD=1e9+7;

char str[maxn];

int main()
{
    int i,j,n,m,a,d,b;
    while(scanf("%s",str+1)!=EOF){
        n=strlen(str+1);
        i=3;
        int s=1,t;
        while(i<=n && str[i]!='e') i++;
        str[i]='0';
        int e=i;
        i++;
        b=0;
        while(i<=n){
            b=b*10+(str[i]-'0');
            str[i]='0';
            i++;
        }
        int p=b+2;
        for(i=3;i<=p;i++){
            if(i>=e) str[i]='0';
            swap(str[i],str[i-1]);
        }
        while(s<p && str[s]=='0') s++;
        if(s==p) s--;
        t=max(p,e);
        while(t>=p && str[t]=='0') t--;
        if(t==p) t--;
        for(i=s;i<=t;i++)
            printf("%c",str[i]);
        puts("");
        memset(str,'\0',sizeof(str));
    }
    return 0;
}




