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

map<string,int> mp;
vector<int> vec[maxn];

int main()
{
    int i,j,n,T,id;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        mp.clear();
        id=0;
        string str;
        int v;
        for(i=1;i<=n;i++){
            vec[i].clear();
            cin>>str>>v;
            if(!mp.count(str))
                mp[str]=++id;
            vec[mp[str]].push_back(v);
        }
        int res=0;
        for(i=1;i<=id;i++){
            sort(vec[i].begin(),vec[i].end());
            if(vec[i].size()==1) res+=vec[i][0];
            else res+=vec[i][vec[i].size()-1]+vec[i][vec[i].size()-2];
        }
        printf("%d\n",res);
    }
    return 0;
}

