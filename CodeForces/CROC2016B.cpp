/****************
*PID:croc2016b
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

const int maxn=200000+10;
LL ans[maxn];
struct Node{
    LL start,L,id;
}s[maxn];
queue<Node> que;

int main()
{
    LL i,j,n,b;
    while(scanf("%I64d%I64d",&n,&b)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%I64d%I64d",&s[i].start,&s[i].L);
            s[i].id=i;
        }
        LL last=s[1].start+s[1].L;
        ans[1]=last;
        for(i=2;i<=n;i++){
            if(last>s[i].start){
                if(que.size()<b)
                    que.push(s[i]);
                else ans[s[i].id]=-1;
                continue;
            }
            if(last==s[i].start){
                if(!que.empty()){
                    Node u=que.front();que.pop();
                    last+=u.L;
                    ans[u.id]=last;
                    que.push(s[i]);
                }else {
                    last+=s[i].L;ans[s[i].id]=last;
                }
                continue;
            }
            while(!que.empty() && last<=s[i].start){
                Node u=que.front();que.pop();
                last+=u.L;ans[u.id]=last;
            }
            if(last<=s[i].start){
                last=s[i].start+s[i].L;
                ans[s[i].id]=last;
            }else {
                if(que.size()<b)
                    que.push(s[i]);
                else ans[s[i].id]=-1;
            }
        }
      //  printf("last=%d\n",last);
        while(!que.empty()){
            Node u=que.front();que.pop();
            if(last>u.start)
                last+=u.L;
            else last=u.start+u.L;
            ans[u.id]=last;
        }
        for(i=1;i<=n;i++)
            printf("%I64d ",ans[i]);
        puts("");
    }
    return 0;
}





