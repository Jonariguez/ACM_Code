/****************
*PID:441c div2
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

const int maxn=300+10;
int a[maxn][maxn];

int main()
{
    int i,j,n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
      //  if(k<=n){
      //      for(i=1;i<k;i++){
      //          printf("%d",i);
      /*/          for(j=1;j<=m;j++)
                    printf(" %d %d",i,j);
                puts("");
            }
            printf("%d",k);
            for(i=k;i<=n;i++){
                if((i-k)&1)
                    for(j=m;j>=1;j--)
                        printf(" %d %d",i,j);
                else for(j=1;j<=m;j++)
                    printf(" %d %d",i,j);
            }
            puts("");
        }else {*/
            int x=1,y=1,sign=1,cnt=0;
            for(int v=1;v<=k;v++){
                if(v<k){
                    printf("2");
                    printf(" %d %d",x,y);
                    y+=sign;
                    if(y>m){
                        x++;y=m;sign=-1;
                    }
                    if(y<=0){
                        x++;y=1;sign=1;
                    }
                    printf(" %d %d\n",x,y);
                    y+=sign;
                    if(y>m){
                        x++;y=m;sign=-1;
                    }
                    if(y<=0){
                        x++;y=1;sign=1;
                    }
                    cnt+=2;
                }else {
                    printf("%d",n*m-cnt);
                    while(cnt<n*m){
                        printf(" %d %d",x,y);
                         y+=sign;
                        if(y>m){
                            x++;y=m;sign=-1;
                        }
                        if(y<=0){
                            x++;y=1;sign=1;
                        }
                        cnt++;
                    }
                }
           // }
        }
        puts("");

    }
    return 0;
}



