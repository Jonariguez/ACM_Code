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

const int maxn=500000+10;
const int MOD=1e9+7;

LL sum[maxn],dp[maxn];
int a[maxn];
int M,st[maxn],tail,head;

LL getUp(int k,int j){
    return dp[k]+sum[k]*sum[k]-dp[j]-sum[j]*sum[j];
}

LL getDown(int k,int j){
    return 2*(sum[k]-sum[j]);
}

bool better2(int k,int j,LL cmp){
    return getUp(k,j)>=getDown(k,j)*cmp;
}

bool better3(int k,int j,int i){    //(i,j)和(j,k)比，或者(j,i)和(k,j)比，顺序不能乱，
    return getUp(i,j)*getDown(j,k)<=getUp(j,k)*getDown(i,j);
}

int ask(LL v){
    while(head<tail-1 && better2(st[head],st[head+1],v)) head++;
    return st[head];
}

int main()
{
    int i,j,n;
    while(scanf("%d%d",&n,&M)!=EOF){
        sum[0]=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        head=tail=0;
        st[tail++]=0;
        dp[0]=0;
        for(i=1;i<=n;i++){
            int p=ask(sum[i]);
            dp[i]=dp[p]+(sum[i]-sum[p])*(sum[i]-sum[p])+M;
            while(head<tail-1 && better3(st[tail-2],st[tail-1],i)) tail--;
            st[tail++]=i;
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}

