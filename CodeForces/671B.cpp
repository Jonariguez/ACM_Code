/****************
*PID:671b div1
*Auth:Jonariguez
*****************
¶þ·Ö
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

const int maxn=500000+10;

int a[maxn];

int main()
{
    int i,j,n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        LL sum=0;
        for(i=1;i<=n;i++){
            sc(a[i]);
            sum+=a[i];
        }
        sort(a+1,a+n+1);
        if(a[1]==a[n]){
            puts("0");continue;
        }
        int l=(sum+n-1)/n,r=a[n],resr=0;
        while(l<=r){
            int m=(l+r)/2;
            LL tot=0;
            for(i=1;i<=n;i++)
                if(a[i]>m) tot+=a[i]-m;
            if(tot>k)
                l=m+1;
            else {
                resr=m;
                r=m-1;
            }
        }
        l=a[1];r=sum/n;
        int resl=0;
        while(l<=r){
            int m=(l+r)/2;
            LL tot=0;
            for(i=1;i<=n;i++)
                if(a[i]<m) tot+=m-a[i];
            if(tot>k)
                r=m-1;
            else {
                resl=m;
                l=m+1;
            }
        }
        printf("%d\n",resr-resl);
    }
    return 0;
}

