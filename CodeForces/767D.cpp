/****************
*PID:
*Auth:Jonariguez
*****************
贪心+二分+双指针
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

const int maxn=1000000+10;
const int MOD=1e9+7;

struct node{
    int v,id;
}s[maxn];

int cmp(const node &x,const node &y){
    return x.v<y.v;
}

int n,m,k,a[maxn];

bool C(int x){
    int i,j,cnt=0,c=0;
    i=1;j=m-x+1;c=n+x;
    while(c){
        int t;
        if(i==n+1)
            t=s[j].v;
        else if(j==m+1)
            t=a[i];
        else t=min(a[i],s[j].v);
        if(c<=k)
            return t>=cnt;
        if(t<cnt) return false;
        int temp=k;
        while(temp--){
            if(i==n+1) j++;
            else if(j==m+1) i++;
            else if(a[i]<=s[j].v) i++;
            else if(a[i]>s[j].v) j++;
        }
        c-=k;
        cnt++;
    }
    return true;
}


int main()
{
    int i,j;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=m;i++){
            scanf("%d",&s[i].v);
            s[i].id=i;
        }
        sort(a+1,a+n+1);
        sort(s+1,s+m+1,cmp);
        int l=0,r=m+1,res=-1;
        while(l<r){
            int M=(l+r)/2;
            if(C(M)){
                res=M;
                l=M+1;
            }else r=M;
        }
        if(res==-1 && C(0)) res=0;
        printf("%d\n",res);
        if(res>0){
            for(i=m;i>=m-res+1;i--)
                printf("%d ",s[i].id);
            puts("");
        }
    }
    return 0;
}
