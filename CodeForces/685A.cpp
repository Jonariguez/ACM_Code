/****************
*PID:div1 a
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
vector<int> bit1,bit2;
int cntn,cntm;

int cal1(int n){
    int res=0;
    while(n){
        res++;
        n/=7;
    }
    return res;
}

int caln(int n){
    int res=0;
    bit1.clear();
    while(n){
        res++;
        bit1.push_back(n%7);
        n/=7;
    }
    while(bit1.size()<cntn)
        bit1.push_back(0);
    return res;
}

int calm(int n){
    int res=0;
    bit2.clear();
    while(n){
        res++;
        bit2.push_back(n%7);
        n/=7;
    }
    while(bit2.size()<cntm)
        bit2.push_back(0);
    return res;
}

bool ok(){
    int v[20];
    memset(v,0,sizeof(v));
    int i;
    for(i=0;i<bit1.size();i++){
        if(v[bit1[i]]) return false;
        v[bit1[i]]++;
    }
    for(i=0;i<bit2.size();i++){
        if(v[bit2[i]]) return false;
        v[bit2[i]]++;
    }
    return true;
}


int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n>1)
            cntn=cal1(n-1);
        else cntn=1;
        if(m>1)
            cntm=cal1(m-1);
        else cntm=1;
      //  printf("cntn=%d cntm=%d\n",cntn,cntm);
        if(cntn+cntm>=8){
            puts("0");continue;
        }
        int res=0;
        for(i=0;i<n;i++){
            caln(i);
            for(j=0;j<m;j++){
                calm(j);
                if(ok()){
                  //  printf("i=%d j=%d\n",i,j);
                    res++;
                }

            }
        }
        pfn(res);
    }
    return 0;
}


