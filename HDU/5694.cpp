/****************
*PID:hdu5694
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

const int maxn=100000+10;
const LL INF=1e18;
LL len[111];
vector<LL> vec;

LL solve(LL n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 2;
    int id=lower_bound(vec.begin(),vec.end(),n)-vec.begin();
  //  printf("n=%I64d vec[id]=%I64d\n",n,vec[id]);
    if(vec[id]==n)
        return vec[id]/2+1;
    LL res=vec[id-1]/2+1+1;
    n-=vec[id-1]+1;
    if(n==0) return res;
    LL L=vec[id-1];     //思想是，对于前面的vec[id-1]的长度里的B已经求出来了，剩下后面一段(设长度为len)里B的个数，
    LL sumB=vec[id-1]/2+1;  //等于上一层S[id-1]里后len个字母里D的个数，只需要求出后len个里有x个B，则就有len-x个D，
    LL preB=solve(L-n);   //那么后len个有几个B呢，我们知道S[id-1]里共sumB=vec[id-1]/2+1个B，那么前面一段共
    sumB-=preB;             //preB个B（递归求解），那么后面就有x=tot-preB个B，那么D个数就出来了=len-x=n-x
    return res+(n-sumB);
}

int main()
{
    int i,j,n,T;
    len[0]=1;
    vec.push_back(len[0]);
    for(i=1;i<=60;i++){
        len[i]=len[i-1]*2+1;
        vec.push_back(len[i]);
    }
    sc(T);
    while(T--){
        LL l,r;
        scanf("%I64d%I64d",&l,&r);
        printf("%I64d\n",solve(r)-solve(l-1));
    }
    return 0;
}



