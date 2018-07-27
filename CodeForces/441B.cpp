/****************
*PID:441b div2
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

const int maxn=3000+10;
int vis[maxn];
struct pp{
    int a,b;
}t[maxn],s[maxn];

int cmp(const pp &x,const pp &y){
    if(x.a==y.a)
        return x.b>y.b;
    return x.a<y.a;
}

int main()
{
    int i,j,n,v;
    while(scanf("%d%d",&n,&v)!=EOF){
        for(i=1;i<=n;++i){
            sc(t[i].a);sc(t[i].b);
        }
        sort(t+1,t+n+1,cmp);
        s[1]=t[1];
        int last=1,tot=1;
        for(i=2;i<=n;i++){
            if(t[i].a==s[last].a){
                s[last].b+=t[i].b;
            }else {
                s[++tot]=t[i];
                last=tot;
            }
        }
        int res=0,now=1;
        last=0;
        j=1;s[tot+1].a=3333;
        for(now=1;now<=3001;now++){
            if(now==s[j].a){
                int temp=0;
                if(last){
                    if(v>=last){
                        res+=last;
                        temp=v-last;
                        if(temp<=s[j].b){
                            res+=temp;last=s[j].b-temp;
                        }else {
                            res+=s[j].b;last=0;
                        }
                    }else {
                        res+=v;last=s[j].b;
                    }
                }else {
                    res+=min(v,s[j].b);
                    last=max(0,s[j].b-v);
                }
                j++;
            }else {
                res+=min(v,last);last=0;
            }
        }
        pfn(res);
    }
    return 0;
}



