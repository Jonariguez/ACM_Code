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

const int maxn=100000+10;
const int MOD=1e9+7;

string str[maxn];
map<string,priority_queue<int> > mpq;
priority_queue<int> q,p;
map<string,int> mp;
int a[maxn];

int main()
{
    int i,j,n,k;
    while(scanf("%d%d",&k,&n)!=EOF){
        mp.clear();
        for(i=1;i<=k;i++){
            cin>>str[i]>>a[i];
            mp[str[i]]++;
        }
        string ss;
        int res=0;
        for(i=1;i<=k;i++){
            ss=str[i];
            reverse(ss.begin(),ss.end());
            if(mp[ss]!=0){
                mpq[str[i]].push(a[i]);
            }else if(ss==str[i]){
                res=max(res,a[i]);
            }
        }
        map<string,int>::iterator it;
        it=mp.begin();
        string sv;
        while(it!=mp.end()){
            if((*it).second==0){
                it++;continue;
            }
            ss=(*it).first;
            sv=ss;
            reverse(sv.begin(),sv.end());
            mp[ss]=mp[sv]=0;
            p=mpq[ss];q=mpq[sv];
            while(!q.empty() && !p.empty()){
                int t1=q.top(),t2=p.top();
                if(t1+t2<=0) break;
                res+=t1+t2;
                q.pop();p.pop();
            }
            it++;
        }
        pfn(res);
    }
    return 0;
}






