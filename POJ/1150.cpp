/****************
*PID:poj1150
*Auth:Jonariguez
*****************
http://www.cppblog.com/abilitytao/archive/2009/10/31/99907.html
http://blog.csdn.net/shiwei408/article/details/8739433
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
int cnt[10];
int mod2[4]={6,2,4,8};
int mod3[4]={1,3,9,7};
int mod7[4]={1,7,9,3};
int mod9[4]={1,9,1,9};

int get(int n,int k){
    if(n==0) return 0;
    return n/k+get(n/k,k);
}

int g(int n,int x){ //g(n,x)表示的是小于等于n的奇数中尾数为x的数的个数
    if(n==0) return 0;
    return n/10+(n%10>=x)+g(n/5,x);
}

int cal(int n,int x){
    if(n==0)
        return 0;
    return cal(n/2,x)+g(n,x);
}

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        cnt[2]=get(n,2)-get(n-m,2);
        cnt[5]=get(n,5)-get(n-m,5);
        cnt[3]=cal(n,3)-cal(n-m,3);
        cnt[7]=cal(n,7)-cal(n-m,7);
        cnt[9]=cal(n,9)-cal(n-m,9);
        int res=1;
        if(cnt[2]>cnt[5])
            res=res*mod2[(cnt[2]-cnt[5])%4]%10;
        else if(cnt[2]<cnt[5])
            res=res*5%10;
        res=res*mod3[cnt[3]%4]*mod7[cnt[7]%4]*mod9[cnt[9]%4];
        printf("%d\n",res%10);
    }
    return 0;
}



