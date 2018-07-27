/****************
*PID:hdu5648
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
#define ALL(x) x.begin(),x.end()
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
vector<int> Sub[1<<16];
int n,m,bit;
LL res;

void pre_solve(){
    int i,j;
    for(i=0;i<(1<<16);i++){
        Sub[i].clear();
        for(j=i;;j=(j-1)&i){
            Sub[i].push_back(j);
            if(j==0) break;
        }
        sort(Sub[i].begin(),Sub[i].end());
    }
}

int get(int v,int p){
    int l=0,r=Sub[v].size(),ans=-1;
    while(l<r){
        int M=(l+r)>>1;
        if(Sub[v][M]<=p){
            ans=M;l=M+1;
        }else r=M;
    }
    return ans+1;
}

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
//由低位到高位，处理到pos位时，i&j=a,i|j=b.即暴力枚举and和or的值
//1<=i<=n 1<=j<=m
void dfs(int pos,int a,int b){
    if(a>n) return ;
    if(pos==bit){
        //我们在a的基础上通过补位得到i，并且保证1<=i<=n 且 1<=j<=m，那么方案数就是
        //就是对应该gcd(a,b)的个数。那么怎么保证1<=i<=n 且 1<=j<=m呢，也就说明在a的基础上不能乱补
        //肯定是有个上下界的。设补位的数的大小为s(s一定是should_fill的子集),又因为我们假设i
        //是通过a补位直接得到的，故i<=n -->a+s<=n  ->s<=n-a即为上界R。  而下界间接求出的，
        //should_fill中，有s补给a作为i，那么剩下的should_fill-s补给a作为j，即j=should_fill-s+a<=m
        //should_fill=b-a  ---->j=b-a-s+a<=m  --->s>=b-m，即下界L
        int should_fill=b-a,R=n-a,L=b-m;
        if(a==0){       //要保证i和j都是整数即>=1，故a==0时，should_fill不能全部补成i或者全部补成j
            R=min(R,should_fill-1);L=max(L,1);
        }
        if(L>R) return ;
        int g=gcd(a,b);
        res=(res+1LL*g*(get(should_fill,R)-get(should_fill,L-1)));
        return ;
    }
    //pos位都取0
    dfs(pos+1,a,b);
    //i|j=b的第pos为1，i&j=a的第pos位0
    dfs(pos+1,a,b+(1<<pos));
    //都取1
    dfs(pos+1,a+(1<<pos),b+(1<<pos));
}

void solve(){
    int i,j;
    scanf("%d%d",&n,&m);
    if(n<m)
        swap(n,m);
    bit=0;
    while((1<<bit)<=n) bit++;
    res=0;
    dfs(0,0,0);
    printf("%I64d\n",res);
}

int main()
{
    int T;
    pre_solve();
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}


