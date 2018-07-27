/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(i,n) for(i=0;j<=(n);i++)
#define re(i,n) for(i=1;i<(n);i++)
#define re0(i,n) for(i=0;i<(n);i++)
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
#define PB push_back
#define X first
#define Y second
#define PI acos(-1.0)
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
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
Ll Pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=10+10;
const int MOD=1e9+7;

int vis[maxn],cnt[maxn],a[maxn];
char str[maxn],n;
vector<string> vec;

void dfs(int cur,string st){
    if(cur>n){
        vec.push_back(st);return ;
    }
    int i;
    for(i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            char c='0'+a[i];
            dfs(cur+1,st+c);
            vis[i]=0;
        }
    }
}

int main()
{
    int i,j;
    scanf("%s",str+1);
    n=strlen(str+1);
    for(i=1;i<=n;i++){
        a[i]=str[i]-'0';
        cnt[a[i]]++;
    }
    sort(a+1,a+n+1);
    dfs(1,"");
    sort(vec.begin(),vec.end());
    cout<<vec[0]<<endl;
    for(i=1;i<vec.size();i++){
        if(vec[i]==vec[i-1]) continue;
        cout<<vec[i]<<endl;
    }
    return 0;
}


