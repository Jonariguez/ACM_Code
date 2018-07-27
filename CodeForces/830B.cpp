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

int A[maxn],B[maxn];
vector<int> vec[maxn],p;

int main()
{
    int i,j,n;
    scanf("%d",&n);
    p.clear();
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
        vec[A[i]].push_back(i);
        p.push_back(A[i]);
    }
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    int last=0,cnt=0,tot=n,last2=0;
    LL res=0;
    for(i=0;i<p.size();i++){
        int v=p[i];
        int id=0;
        while(id<vec[v].size()){
            if(vec[v][id]>last)
                break;
            id++;
        }
        if(id>=vec[v].size()){  //
            res+=tot;
            tot-=cnt;
            cnt=vec[v].size();
            last=vec[v][vec[v].size()-1];
        }else {
            cnt+=(vec[v].size()-id);
            //res+=tot;
            //tot-=cnt;
            last=vec[v][vec[v].size()-1];
            if(id>=1){
                res+=tot;
                tot-=cnt;
                last=vec[v][id-1];
                cnt=id;
            }
        }
    }
    res+=tot;
    printf("%I64d\n",res);
    return 0;
}

/*
4
6 3 1 2
*/
