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
#define ALL(x) (x).begin(),(x).end()
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
int a[maxn],bit[maxn];
vector<int> vec;

void add(int i){
    while(i<=100000){
        bit[i]++;
        i+=i&(-i);
    }
}

int sum(int i){
    int res=0;
    while(i>0){
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}

int main()
{
    int i,j,n,res;
    while(scanf("%d",&n)!=EOF){
        vec.clear();
        for(i=1;i<=n;i++){
            sc(a[i]);
            vec.push_back(a[i]);
        }
        sort(ALL(vec));
        vec.erase(unique(ALL(vec)),vec.end());
        for(i=1;i<=n;i++)
            a[i]=(upper_bound(ALL(vec),a[i])-vec.begin());
        res=0;
        memset(bit,0,sizeof(bit));
        for(i=1;i<=n;i++){
            res=max(res,i-1-sum(a[i]-1));
            add(a[i]);
        }
        printf("%d\n",res);
    }
    return 0;
}



