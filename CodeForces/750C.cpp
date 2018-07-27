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

int c[maxn],d[maxn],n;

int C(int x){
    int i;
    for(i=1;i<=n;i++){
        if(x>=1900 && d[i]==2) return 2;    //ธ฿
        if(x<1900 && d[i]==1) return 1;     //ตอ
        x+=c[i];
    }
    return 0;
}

bool ok(int ans){
    for(int i=1;i<=n;i++){
        if(ans<=1899 && d[i]==1) return false;
        if(ans>=1900 && d[i]==2) return false;
        ans+=c[i];
    }
    return true;
}

int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF){
        int mx=MOD,mn=-MOD,res=-MOD-1;
        for(i=1;i<=n;i++)
            scanf("%d%d",&c[i],&d[i]);
        int l=-MOD,r=MOD+1;
        while(l<r){
            int m=(l+r)/2;
            int temp=C(m);
            if(temp<=1){
                if(temp==0) res=m;
                l=m+1;
            }else r=m-1;
        }
        if(ok(res+1)) res++;
        if(res==-MOD-1)
            puts("Impossible");
        else if(res>=MOD)
            puts("Infinity");
        else {
           // printf("res=%d\n",res);
            if(!ok(res)){
                puts("Impossible");continue;
            }
            for(i=1;i<=n;i++){
                res+=c[i];
            }
            printf("%d\n",res);
        }
    }
    return 0;
}

