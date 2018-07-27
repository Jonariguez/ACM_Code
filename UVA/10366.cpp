/****************
*PID:uva10366
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
int z[maxn],r[maxn];
map<int,int> l;

struct Node{
    int pos,hei,v;
};

int main()
{
    int i,j,n,left,right;
    while(scanf("%d%d",&left,&right)){
        if(left==0 && right==0) break;
        int L=0,R=0,idl,idr;
        l.clear();
        for(i=left;i<0;i+=2){
            int x;
            scanf("%d",&x);
            l[i]=x;
            if(L<=l[i]){
                L=l[i];
                idl=i;
            }
        }
        for(i=1;i<=right;i+=2){
            scanf("%d",&r[i]);
            if(R<r[i]){
                R=r[i];idr=i;
            }
        }
        int res=0;
        if(R<L){
            int IDL;
            for(i=-1;i>=left;i-=2){
                if(l[i]>=R){
                    IDL=i;break;
                }
            }
            int yes=0,hh=1e9;
            if(l[IDL]==R) yes=1;    //这里是处理像这样的数据 -11 7 \n 10 2 2 2 2 4 4 4 2 1
            if(IDL!=idl){
                hh=(IDL-idl)*l[IDL];
            }
            res=R*(idr-IDL);
            Node u;
            u.pos=idr;u.hei=R;u.v=0;
            stack<Node> s;
            for(i=idr+2;i<=right;i+=2){
                while(!s.empty() && s.top().hei<=r[i]) s.pop();
                if(s.empty()){
                    u.pos=i;u.hei=r[i];u.v=(i-idr)*u.hei;
                    s.push(u);
                }else {
                    u.pos=i;u.hei=r[i];u.v=(i-s.top().pos)*r[i];
                    s.push(u);
                }
            }
            int sum=0;
            while(!s.empty()){
                sum+=s.top().v;s.pop();
            }
            res+=sum;
            if(yes) res+=min(hh,sum);
            printf("%d\n",res);
        }else if(R>L){
            int IDR;
            for(i=1;i<=right;i+=2){
                if(r[i]>=L){
                    IDR=i;break;
                }
            }
            int yes=0,hh=1e9;
            if(r[IDR]==L) yes=1;
            if(IDR!=idr){
                hh=(idr-IDR)*r[IDR];
            }
            res=L*(IDR-idl);
            Node u;
            u.pos=idl;u.hei=L;u.v=0;
            stack<Node> s;
            for(i=idl-2;i>=left;i-=2){
                while(!s.empty() && s.top().hei<=l[i]) s.pop();
                if(s.empty()){
                    u.pos=i;u.hei=l[i];u.v=(idl-i)*l[i];
                    s.push(u);
                }else {
                    u.pos=i;u.hei=l[i];u.v=(s.top().pos-i)*l[i];
                    s.push(u);
                }
            }
            int sum=0;
            while(!s.empty()){
                sum+=s.top().v;s.pop();
            }
            res+=sum;
            if(yes) res+=min(hh,sum);
            printf("%d\n",res);
        }else {
            res=L*(idr-idl);
            Node u;
            stack<Node> s;
            for(i=idr+2;i<=right;i+=2){
                while(!s.empty() && s.top().hei<=r[i]) s.pop();
                if(s.empty()){
                    u.pos=i;u.hei=r[i];u.v=(i-idr)*r[i];
                    s.push(u);
                }else {
                    u.pos=i;u.hei=r[i];u.v=(i-s.top().pos)*r[i];
                    s.push(u);
                }
            }
            int temp=0;
            while(!s.empty()){
                temp+=s.top().v;s.pop();
            }
            for(i=idl-2;i>=left;i-=2){
                while(!s.empty() && s.top().hei<=l[i]) s.pop();
                if(s.empty()){
                    u.pos=i;u.hei=l[i];u.v=(idl-i)*l[i];
                    s.push(u);
                }else {
                    u.pos=i;u.hei=l[i];u.v=(s.top().pos-i)*l[i];
                    s.push(u);
                }
            }
            int temp2=0;
            while(!s.empty()){
                temp2+=s.top().v;s.pop();
            }
          //  pfn(temp);pfn(temp2);
            res+=2*min(temp,temp2);
            printf("%d\n",res);
        }
    }
    return 0;
}


