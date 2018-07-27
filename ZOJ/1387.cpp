/****************
*PID:zoj1387
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
int dp[maxn];
char table[26][10]={{".-"},{"-..."},{"-.-."},{"-.."},
    {"."},{"..-."},{"--."},{"...."},{".."},{".---"},{"-.-"},{".-.."},
    {"--"},{"-."},{"---"},{".--."},{"--.-"},{".-."},{"..."},{"-"},
    {"..-"},{"...-"},{".--"},{"-..-"},{"-.--"},{"--.."}
};

char buf[maxn][105],s[maxn],str[40];

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        int m;
        m=strlen(s+1);
        sc(n);
        for(i=0;i<n;i++){
            scanf("%s",str);
            buf[i][0]='\0';
            int l=strlen(str);
            for(j=0;j<l;j++)
                strcat(buf[i],table[str[j]-'A']);
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(i=0;i<m;i++){
            if(dp[i]){
                for(j=0;j<n;j++){
                    int len=strlen(buf[j]);
                    if(i+len>m) continue;
                    if(strncmp(s+i+1,buf[j],len)==0)
                        dp[i+len]+=dp[i];
                }
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}




