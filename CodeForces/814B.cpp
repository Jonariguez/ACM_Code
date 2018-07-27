/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(j,n) for(j=0;j<=(n);j++)
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

const int maxn=200000+10;
const int MOD=1e9+7;

int a[maxn],b[maxn],vis[maxn],vis2[maxn],res[maxn],n;

bool check(){
    int c=0,d=0;
    for(int i=1;i<=n;i++)
        if(res[i]!=a[i]) c++;
    for(int i=1;i<=n;i++)
        if(res[i]!=b[i]) d++;
    return (c==1 && d==1);
}

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        vis[a[i]]++;
    }
    int cnt=0,p=0,q=0,A=0,B=0;
    for(i=1;i<=n;i++){
        sc(b[i]);
        vis2[b[i]]++;
        if(a[i]!=b[i]){
            cnt++;
            if(cnt==1) A=i;
            else B=i;
        }else res[i]=a[i];
    }
    for(p=1;p<=n;p++) if(vis[p]==0) break;
    for(q=1;q<=n;q++) if(vis2[q]==0) break;
    if(p!=q){
        res[A]=p;res[B]=q;
        if(check()){
            for(i=1;i<=n;i++) printf("%d ",res[i]);
            puts("");return 0;
        }else {
            swap(res[A],res[B]);
            for(i=1;i<=n;i++) printf("%d ",res[i]);
            puts("");return 0;
        }
    }else {
        for(i=1;i<=n;i++)
            if(i==A) printf("%d ",p);
            else printf("%d ",res[i]);
        puts("");
    }
    return 0;
}




