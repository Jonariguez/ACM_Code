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

LL a[maxn];
struct node{
    LL v;
    bool operator < (const node &r) const{
        return abs(v)>abs(r.v);
    }
};

priority_queue<node> que;

int main()
{
    int i,j,n,k;
    LL x;
    scanf("%d%d%I64d",&n,&k,&x);
    int cnt=0;
    node u;
    for(i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
        if(a[i]<0) cnt++;
        u.v=a[i];
        que.push(u);
    }
    if(cnt&1){
        while(k--){
            u=que.top();que.pop();
            if(u.v<0){
                while(que.empty() || abs(u.v)<=abs(que.top().v))
                    u.v-=x;
                que.push(u);
            }else {
                while(que.empty() || abs(u.v)<=abs(que.top().v))
                    u.v+=x;
                que.push(u);
            }
        }
    }else {
        u=que.top();que.pop();
        if(u.v<0){
            while(k-- && u.v<0) u.v+=x;
            que.push(u);
        }else {
            while(k-- && u.v>=0) u.v-=x;
            que.push(u);
        }
        while(k--){
            u=que.top();que.pop();
            if(u.v<0){
                while(que.empty() || abs(u.v)<=abs(que.top().v))
                    u.v-=x;
                que.push(u);
            }else {
                while(que.empty() || abs(u.v)<=abs(que.top().v))
                    u.v+=x;
                que.push(u);
            }
        }
    }
    while(!que.empty()){
        printf("%I64d ",que.top().v);
        que.pop();
    }
    return 0;
}



