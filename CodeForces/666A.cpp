/****************
*PID:666a div1
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
string str;
//dp[i][0]：从位置i开始，长度为2的串是否可以，dp[i][1]同理长度为3
int dp[maxn][2];
set<string> res;
int main()
{
    int i,j,n;
    memset(dp,0,sizeof(dp));
    while(cin>>str){
        n=str.size();
        for(i=n-1;i>=5;i--){
            if(i+2==n){
                dp[i][0]=1;
                res.insert(str.substr(i,2));
            }
            if(i+3==n){
                dp[i][1]=1;
                res.insert(str.substr(i,3));
            }
            //求dp[i][0],即长度为2的
            if(dp[i+2][1] || (dp[i+2][0] && str.substr(i,2)!=str.substr(i+2,2))){
                dp[i][0]=1;
                res.insert(str.substr(i,2));
            }
            if(dp[i+3][0] || (dp[i+3][1] && str.substr(i,3)!=str.substr(i+3,3))){
                dp[i][1]=1;
                res.insert(str.substr(i,3));
            }
        }
        printf("%d\n",res.size());
        set<string>::iterator it;
        it=res.begin();
        while(it!=res.end())
            cout<<(*it)<<endl,it++;
        res.clear();
    }
    return 0;
}





