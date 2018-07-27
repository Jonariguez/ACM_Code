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
#define SS(x,y) scanf("%d%d",&x,&y)
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
#include <bitset>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef long long Ll;
Ll Pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=200000+10;
const int MOD=1e9+7;

LL u[11],v[11];

LL cal0(LL n){
    if(n<0) return 0;
    if(n==0) return 1;
    LL tn=n,ten=1,res=0,cnt=0;
    while(tn){
        LL temp=tn%10;
        if(cnt==0){
            res+=(n/(ten*10)+1)*ten;
        }else {
            if(temp==0){
                res+=(n/(ten*10)-1)*ten;
                res+=n%ten+1;
            }else
                res+=(n/(ten*10))*ten;
        }
        ten*=10;
        tn/=10;
        cnt++;
    }
    return res;
}

LL cal(LL n,LL i){
    LL tn=n,ten=1,res=0;
    while(tn){
        LL temp=tn%10;
        if(temp<i)
            res+=n/(ten*10)*ten;
        else if(temp==i){
            res+=n/(ten*10)*ten;
            res+=n%ten+1;
        }else
            res+=(n/(ten*10)+1)*ten;
        ten*=10;
        tn/=10;
    }
    return res;
}



void solve(LL n,LL *f){
    memset(f,0,sizeof(f));
    if(n<0) return ;
    f[0]=cal0(n);
    for(LL i=1;i<=9;i++)
        f[i]=cal(n,i);
}

int main()
{
    int i,j,n;
    LL a,b;
    scanf("%I64d%I64d",&a,&b);
    solve(b,u);
    solve(a-1,v);
    //for(i=0;i<10;i++)
     //   printf("i=%d u=%I64d v=%I64d\n",i,u[i],v[i]);
    for(i=0;i<10;i++)
        printf("%I64d\n",u[i]-v[i]);
    return 0;
}


