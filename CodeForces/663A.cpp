/****************
*PID:663a div1
*Auth:Jonariguez
*****************
先初始化每个？为1，然后计算出结果res再根据res和n的关系来调整每个数
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
char str[maxn];
int add,mi,sign[maxn];
int a[maxn];

int main()
{
    int i,j,n,m;
    gets(str+1);
    m=strlen(str+1);
    j=m;
    while(j>=1 && str[j]!=' ') j--;
    n=0;
    while(++j<=m)
        n=n*10+(str[j]-'0');
  //  printf("n=%d\n",n);
    add=mi=0;
    i=1;
    int cnt=0,tot=0;
    while(str[i]!='='){
        if(str[i]=='+'){
            add++;sign[++tot]=1;
        }
        if(str[i]=='-'){
            mi++;sign[++tot]=-1;
        }
        if(str[i]=='?') cnt++;
        i++;
    }
    if(mi==0 && cnt>n){
        puts("Impossible");return 0;
    }
    if(cnt==1){
        puts("Possible");
        printf("%d = %d\n",n,n);return 0;
    }
    int now=0;
    sign[0]=1;
    for(i=1;i<=cnt;i++){
        a[i]=1;
        now+=sign[i-1];
    }
    now-=n;
    if(now<0){
        for(i=1;i<=cnt;i++){
            if(sign[i-1]<0) continue;
            while(now<0 && a[i]<n){
                now++;a[i]++;
            }
            if(now==0) break;
        }
    }else if(now>0){
        for(i=1;i<=cnt;i++){
            if(sign[i-1]>0) continue;
            while(now>0 && a[i]<n){
                now--;a[i]++;
            }
            if(now==0) break;
        }
    }
    if(now)
        puts("Impossible");
    else {
        puts("Possible");
        printf("%d ",a[1]);
        for(i=2;i<=cnt;i++){
            if(sign[i-1]<0)
                printf("- ");
            else printf("+ ");
            printf("%d ",a[i]);
        }
        printf("= %d\n",n);
    }
    return 0;
}





