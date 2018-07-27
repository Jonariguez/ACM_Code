/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(j,n) for(j=0;j<=(n);j++)
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

int a[4][4];

int main()
{
    int i,j,n;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++)
            sc(a[i][j]);
    }
    int yes=0;
    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            if(a[i][j]){
                if(j==0 && a[(i+3)%4][3]){
                    yes=1;
                }
                if(j==1 && a[(i+2)%4][3])
                    yes=1;
                if(j==2 && a[(i+1)%4][3])
                    yes=1;
            }
            if(a[i][j] && a[i][3]) yes=1;
        }
    }
    if(yes)
        puts("YES");
    else puts("NO");
    return 0;
}




