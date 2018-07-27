/****************
*PID:51nod 1315
*Auth:Jonariguez
*****************
把和x的二进制表示中是1的位置，相同的数就好
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

const int maxn=200000+10;
const int MOD=1e9+7;

int bit[40];

int main()
{
    int i,j,n,x;
    scanf("%d%d",&n,&x);
    memset(bit,0,sizeof(bit));
    for(i=1;i<=n;i++){
        int v;
        sc(v);
        if((v&x)!=v) continue;  //重要
        for(j=0;j<=32;j++){
            bit[j]+=(v%2);
            v/=2;
        }
    }
    int res=111;
    for(i=0;i<=32;i++){
        if(x&1) res=min(res,bit[i]);
        x/=2;
    }
    pfn(res);
    return 0;
}


