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

const int maxn=1000+10;
const int MOD=1e9+7;

char stra[maxn],strb[maxn];
int a[maxn],b[maxn];
int visa[12],visb[12];
vector<int> va,vb;

int main()
{
    int i,j,n,x;
    while(scanf("%d",&n)!=EOF){
        scanf("%s%s",stra+1,strb+1);
        for(i=1;i<=n;i++){
            a[i]=stra[i]-'0';
            b[i]=strb[i]-'0';
        }
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        memset(visa,0,sizeof(visa));
        va.clear();vb.clear();
        i=1;j=1;
        while(i<=n && j<=n){
            if(a[i]==b[j]){
                i++;j++;
            }else if(a[i]<b[j]){
                va.push_back(a[i]);i++;
            }else {
                vb.push_back(b[j]);j++;
            }
        }
        if(i>n)
            for(;j<=n;j++)
                vb.push_back(b[j]);
        if(j>n)
            for(;i<=n;i++)
                va.push_back(a[i]);
        int cnt=0;
        for(i=va.size()-1,j=vb.size()-1;i>=0 && j>=cnt;){
            if(va[i]<vb[j]){
                i--;j--;
            }else {
                cnt++;i--;
            }
        }
        printf("%d\n",cnt);
        va.clear();vb.clear();
        for(i=1;i<=n;i++){
            va.push_back(a[i]);
            vb.push_back(b[i]);
        }
        cnt=0;
        int res=0;
        for(i=va.size()-1,j=vb.size()-1;i>=0 && j>=cnt;){
            if(va[i]<vb[j]){
                i--;j--;res++;
            }else {
                cnt++;i--;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}


