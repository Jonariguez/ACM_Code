/****************
*PID:hdu4452
*Auth:Jonariguez
*****************
注意两者相遇了就忽略turn_left
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
int n;

struct node{
    int x,y,s,t;
    char dir;
}T,J;

void walk(node &w){
    int step=w.s;
    if(w.dir=='W'){ //西
        if(w.s<w.y)
            w.y-=w.s;
        else {
            int temp=w.s-(w.y-1);
            w.y=temp+1;w.dir='E';
        }
    }else if(w.dir=='E'){
        if(w.s<=n-w.y)
            w.y+=w.s;
        else {
            int temp=w.s-(n-w.y);
            w.y=n-temp;w.dir='W';
        }
    }else if(w.dir=='N'){
        if(w.s<w.x)
            w.x-=w.s;
        else {
            int temp=w.s-(w.x-1);
            w.x=temp+1;w.dir='S';
        }
    }else {
        if(w.s<=n-w.x)
            w.x+=w.s;
        else {
            int temp=w.s-(n-w.x);
            w.x=n-temp;w.dir='N';
        }
    }
}

void change(){
    char temp=T.dir;
    T.dir=J.dir;
    J.dir=temp;
}

void turn_around(node &w){
    if(w.dir=='W') w.dir='E';
    else if(w.dir=='E') w.dir='W';
    else if(w.dir=='S') w.dir='N';
    else if(w.dir=='N') w.dir='S';
}

void turn_left(node &w){
    if(w.dir=='W') w.dir='S';
    else if(w.dir=='S') w.dir='E';
    else if(w.dir=='E') w.dir='N';
    else if(w.dir=='N') w.dir='W';
}

int main()
{
    int i,j;
    while(scanf("%d",&n),n){
        char str[5];
        scanf("%s%d%d",str,&T.s,&T.t);
        char ori=str[0];
        T.dir=str[0];
        T.x=1;T.y=1;
        scanf("%s%d%d",str,&J.s,&J.t);
        J.dir=str[0];
        J.x=n;J.y=n;
        int k,now=0;
        scanf("%d",&k);
        while(now<k){
            walk(T);
            walk(J);
            if(T.x==J.x && T.y==J.y){
                change();
                now++;continue;
            }
            now++;
            if(now%T.t==0)
                turn_left(T);
            if(now%J.t==0)
                turn_left(J);
        }
        printf("%d %d\n",T.x,T.y);
        printf("%d %d\n",J.x,J.y);
    }
    return 0;
}




