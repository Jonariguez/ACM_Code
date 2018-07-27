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
#include <cctype>
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
const int S=100000;

LL T,a[maxn];
int n,vis[maxn];
vector<LL> p[maxn];

queue<LL> que1,que2;

inline int readint(){
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    int x=0;
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return x;
}

inline LL readInt(){
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    LL x=0;
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return x;
}

int buf[20];

inline void print(int i){
    int p=0;
    buf[0]=0;
    if(i==0)
        p++;
    else while(i){
        buf[p++]=i%10;
        i/=10;
    }
    for(int j=p-1;j>=0;j--)
        putchar('0'+buf[j]);
}

bool C(int m){
    if(m<=1) return false;
    while(!que1.empty()) que1.pop();
    while(!que2.empty()) que2.pop();
    LL cost=0,temp=0;
    int i=1;
    int sum=n;
    if((n-1)%(m-1)){
        for(;i<=(n-1)%(m-1)+1;i++){
            temp+=a[i];sum--;
        }
        que2.push(temp);sum++;
    }
    for(;i<=n;i++)
        que1.push(a[i]);
    //printf("m=%d\n",m);
    while(!que1.empty() || !que2.empty()){
        if(que1.empty() && que2.empty()) break;
        int cnt=m;
        temp=0;
        while(cnt &&(!que1.empty() || !que2.empty())){
            LL v1=0,v2=0;
            cnt--;
            if(que1.empty()){
                temp+=que2.front();
                que2.pop();
            }else if(que2.empty()){
                temp+=que1.front();
                que1.pop();
            }else {
                v1=que1.front();
                v2=que2.front();
                if(v1<v2){
                    temp+=v1;que1.pop();
                }else {
                    temp+=v2;que2.pop();
                }
            }
        }
        cost+=temp;
        if(cost>T) return false;
        que2.push(temp);
    }
    //printf("cost=%I64d\n",cost);
    /*while(!que1.empty()){
        cost+=que1.front();que1.pop();
    }
    while(!que2.empty()){
        cost+=que2.front();que2.pop();
    }*/
    //printf("cost=%I64d\n",cost);
    return cost<=T;
}


int main()
{
    int i,j,kcase;
    kcase=readint();
    while(kcase--){
        //scanf("%d%lld",&n,&T);
        n=readint();
        T=readInt();
        for(i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
        }
        sort(a+1,a+n+1);
        int l=1,r=n,res=2;
        while(l<r){
            int m=(l+r)/2;
            if(C(m)){
                //res=m;
                r=m;
            }else l=m+1;
        }
        printf("%d\n",r);
    }
    return 0;
}
