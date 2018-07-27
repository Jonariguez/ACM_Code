/****************
*PID:425a div1
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
int a[maxn],b[maxn],n,k;

int cal(int x,int y){
    priority_queue<int,vector<int>,greater<int> > que;
    int i,sum=0,res=0;
    for(i=x;i<=y;i++){
        sum+=a[i];
        que.push(a[i]);
    }
    for(i=1;i<=n;i++) b[i]=a[i];
    res=sum;
    for(int j=0;j<k;j++){
        int v=-1;
        for(i=1;i<=n;i++)
            if((i<x || i>y) && (v==-1 || b[v]<b[i]))
                v=i;
        int t=que.top();que.pop();
        sum-=t;sum+=b[v];
        que.push(b[v]);
        res=max(res,sum);
        b[v]=t;
    }
    return res;
}

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&k)!=EOF){
        for(i=1;i<=n;i++) sc(a[i]);
        if(n==1){
            printf("%d\n",a[1]);continue;
        }
        int res=-1100;
        for(i=1;i<=n;i++){
            for(j=i;j<=n;j++){
                res=max(res,cal(i,j));
            }
        }
        pfn(res);
    }
    return 0;
}


