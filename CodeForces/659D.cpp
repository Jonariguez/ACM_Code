/****************
*PID:659d div2
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
int x[maxn],y[maxn],n;
struct node{
    int x,y;
    char dir;
};
//
bool left(int i,node &w){
    bool ok=false;
    if(w.dir=='N'){ //±±
        if(w.x>x[i]){
            w.x=x[i];ok=true;
            w.dir='W';
        }else{
            w.x=x[i];w.dir='E';
        }
    }else if(w.dir=='S'){ //ÄÏ
        if(w.x<x[i]){
            w.x=x[i];ok=true;
            w.dir='E';
        }else {
            w.x=x[i];w.dir='W';
        }
    }else if(w.dir=='W'){
        if(w.y>y[i]){
            w.y=y[i];ok=true;
            w.dir='S';
        }else {
            w.y=y[i];w.dir='N';
        }
    }else if(w.dir=='E'){
        if(w.y<y[i]){
            w.y=y[i];ok=true;
            w.dir='N';
        }else {
            w.y=y[i];w.dir='S';
        }
    }
    return ok;
}

int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n+1;i++){
            sc(x[i]);sc(y[i]);
        }
        node now;
        now.x=x[2];now.y=y[2];
        now.dir='N';
        int res=0;
        for(i=3;i<=n+1;i++){
            if(left(i,now)){
                res++;
            }
        }
        pfn(res);
    }
    return 0;
}


