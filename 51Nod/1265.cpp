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

const int maxn=200000+10;
const int MOD=1e9+7;

struct Point{
    int x,y,z;
}s[5],v[5];

int main()
{
    int i,j,T;
    sc(T);
    while(T--){
        for(i=1;i<=4;i++) scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].z);
        v[1].x=s[2].x-s[1].x;
        v[1].y=s[2].y-s[1].y;
        v[1].z=s[2].z-s[1].z;

        v[2].x=s[3].x-s[1].x;
        v[2].y=s[3].y-s[1].y;
        v[2].z=s[3].z-s[1].z;

        v[3].x=s[4].x-s[1].x;
        v[3].y=s[4].y-s[1].y;
        v[3].z=s[4].z-s[1].z;

        v[4].x=v[1].y*v[2].z-v[2].y*v[1].z;
        v[4].y=v[1].z*v[2].x-v[2].z*v[1].x;
        v[4].z=v[1].x*v[2].y-v[2].x*v[1].y;

        int res=v[3].x*v[4].x+v[3].y*v[4].y+v[3].z*v[4].z;
        if(res)
            puts("No");
        else puts("Yes");
    }
    return 0;
}



