/****************
*PID:51nod1298
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

double c[5];

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        double x,y,r;
        scanf("%lf%lf%lf",&x,&y,&r);
        for(i=1;i<=3;i++){
            int a,b;
            scanf("%lf%lf",&a,&b);
            c[i]=(a-x)*(a-x)+(b-y)*(b-y);
        }
        sort(c+1,c+4);
        double u=c[1]-r*r;
        double v=c[3]-r*r;
        if(u*v<=0)
            puts("Yes");
        else puts("No");
    }
    return 0;
}

