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
int dx[8]={0,1,0,-1,1,1,-1,-1};
int dy[8]={1,0,-1,0,-1,1,-1,1};

int main()
{
    int i,j,n;
    char str[22];
    scanf("%s",str+1);
    int c=(str[1]-'a')+1;
    int r=(str[2]-'0');
   // printf("c=%d r=%d\n",c,r);
    int res=0;
    for(i=0;i<8;i++){
        int x=c+dx[i],y=r+dy[i];
        if(x<=8 && x>=1 && y<=8 && y>=1){
          //  printf("x=%d y=%d\n",x,y);
          res++;
        }
    }
    pfn(res);
    return 0;
}


