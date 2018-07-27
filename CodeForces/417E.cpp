/****************
*PID:417e div2
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

const int maxn=100+10;

bool judge(int x){
    int k=(int)sqrt(x+0.5);
    if(k*k==x) return true;
    return false;
}

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int a,b,c,d;
        while(true){
            a=rand()%100+1;
            b=rand()%100+1;
            c=rand()%100+1;
            d=rand()%100+1;
            int x1=(m-1)*a*a+b*b;
            int x2=(n-1)*a*a+c*c;
            int x3=(m-1)*c*c+d*d;
            int x4=(n-1)*b*b+d*d;
            if(judge(x1) && judge(x2) && judge(x3) && judge(x4)) break;
        }
        for(i=1;i<n;i++){
            for(j=1;j<m;j++) printf("%d ",a);
            printf("%d\n",b);
        }
        for(i=1;i<m;i++)
            printf("%d ",c);
        printf("%d\n",d);
    }
    return 0;
}




