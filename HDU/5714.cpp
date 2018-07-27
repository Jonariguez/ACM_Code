/****************
*PID:hdu5714
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

const int maxn=100000+3;
const int Size=1e6+1e4;
int sum[maxn*2];
int Left[maxn*2];

struct pp{
    int x,y,z,d;
}s[maxn];

struct node{
    int v,le,a;
}b[maxn*2];

int cmp(const node &x,const node &y){
    if(x.v==y.v){
        return x.le>y.le;
    }
    return x.v<y.v;
}

int main()
{
    int i,j,n,m,L,T,kcase=1;
    sc(T);
    while(T--){
        scanf("%d",&n);
        int x,y,z,d,mr=0,ml=1e8,f=0,cnt=0;
        for(i=1;i<=n;i++){
            scanf("%d%d%d%d",&x,&y,&z,&d);
            if(y-x>2*z) continue;
            cnt++;
            s[cnt].x=x;s[cnt].y=y;s[cnt].z=z;s[cnt].d=d;
        }
        if(cnt==0){
            printf("Case #%d:\n0\n",kcase++);
            continue;
        }
        int cnt1=0,cnt2=0;
        for(i=1;i<=cnt;i++){
            x=s[i].x;y=s[i].y;z=s[i].z;d=s[i].d;
            int l=y-z,r=x+z;
            if(d==1){
                cnt1++;
                b[cnt1].v=l;b[cnt1].le=1;b[cnt1].a=1;
                cnt1++;
                b[cnt1].v=r;b[cnt1].le=-1;b[cnt1].a=1;
            }else {
                cnt1++;
                b[cnt1].v=l;b[cnt1].le=1;b[cnt1].a=0;
                cnt1++;
                b[cnt1].v=r;b[cnt1].le=-1;b[cnt1].a=0;
            }
        }
        sort(b+1,b+cnt1+1,cmp);
        memset(sum,0,sizeof(sum));
        Left[0]=sum[0]=0;
        int c1=0,c2=0;
        for(i=1;i<=cnt1;i++){
            if(b[i].a){
                c1+=b[i].le;
                Left[i]=max(Left[i-1],c1);
                sum[i]=sum[i-1];
            }else {
                c2+=b[i].le;
                sum[i]=c2;
                Left[i]=Left[i-1];
            }
        }
        int res=0;
        for(i=cnt1;i>=1;i--){
            sum[i]=max(sum[i],sum[i+1]);
            res=max(res,Left[i]+sum[i]);
        }
        printf("Case #%d:\n%d\n",kcase++,res);
    }
    return 0;
}
