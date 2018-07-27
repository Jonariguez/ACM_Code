/****************
*PID:665c edu12
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("%d%d",&x,&y)
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
    int i,j,n,m;
    while(scanf("%s",str+1)!=EOF){
        n=strlen(str+1);
        if(n==1){
            puts(str+1);continue;
        }
        if(n==2){
            if(str[1]!=str[2])
                puts(str+1);
            else {
                char c='a';
                while(c==str[2]) c++;
                str[1]=c;
                puts(str+1);
            }
            continue;
        }
        int res=0;
        printf("%c",str[1]);
        for(i=2;i<n;i++){
            if(str[i]==str[i-1]){
                char c='a';
                while(c==str[i-1] || c==str[i+1]) c++;
                str[i]=c;
            }
            printf("%c",str[i]);
        }
        if(str[n]==str[n-1]){
            char c='a';
            while(c==str[n-1]) c++;
            str[n]=c;
        }
        printf("%c\n",str[n]);
    }
    return 0;
}



