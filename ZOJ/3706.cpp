/****************
*PID:zoj3706
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

const int maxn=1000+10;
int vis[maxn],a[4];
set<int> ss;

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&a[0],&a[1]);
        int b[5],res=0;
        for(i=0;i<2;i++){
            for(j=1;j<a[i];j++){
                b[1]=j;b[2]=a[i]-j;b[3]=a[(i^1)];
                ss.clear();
                ss.insert(b[1]);ss.insert(b[2]);ss.insert(b[3]);
                ss.insert(b[1]+b[2]);ss.insert(abs(b[1]-b[2]));
                ss.insert(b[1]+b[3]);ss.insert(abs(b[1]-b[3]));
                ss.insert(b[3]+b[2]);ss.insert(abs(b[3]-b[2]));
                ss.insert(b[1]+b[2]+b[3]);
                ss.insert(abs(b[1]+b[2]-b[3]));
                ss.insert(abs(b[1]+b[3]-b[2]));
                ss.insert(abs(b[3]+b[2]-b[1]));
                int cnt=0;
                set<int>::iterator it;
                it=ss.begin();
                while(it!=ss.end()){
                    if((*it)) cnt++;
                    it++;
                }
                res=max(res,cnt);
            }
        }
        pfn(res);
    }
    return 0;
}





