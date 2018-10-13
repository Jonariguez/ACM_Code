/****************
*PID:bzoj1007
*Auth:Jonariguez
*****************
因为可见的直线组成一个下凸的半凸包，所以用类似于凸包
的做法，对于加进来的直线，如果它与st[top-2]的交点在
st[top-2]与st[top-1]的交点的左边，则将st[top-1]弹出。
注意处理平行线
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
#define eps 1e-9
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=50000+5;
const int MOD=1e9+7;

bool ans[maxn];

struct Line{
    double A,B;
    int id;
}L[maxn],st[maxn];

int cmp(const Line &x,const Line &y){
    if(fabs(x.A-y.A)<eps)
        return x.B<y.B;
    return x.A<y.A;
}

double calx(const Line &x,const Line &y){
    return (y.B-x.B)/(x.A-y.A);
}

void MonSt(int n){
    int i,j,top=0;
    sort(L+1,L+n+1,cmp);
    for(i=1;i<=n;i++){
        //第一个条件处理平行线的情况
        while(top>=1 && st[top-1].A==L[i].A || top>=2 && calx(st[top-2],st[top-1])>=calx(st[top-2],L[i]))
            top--;
        st[top++]=L[i];
    }
    memset(ans,0,sizeof(ans));
    for(i=0;i<top;i++)
        ans[st[i].id]=1;
    for(i=1;i<=n;i++)
        if(ans[i])
            printf("%d ",i);
    puts("");
}


int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lf%lf",&L[i].A,&L[i].B);
        L[i].id=i;
    }
    MonSt(n);
    return 0;
}



