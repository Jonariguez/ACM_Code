/****************
*PID:1695
*Auth:Jonariguez
*****************
解法：容斥原理
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
vector<int> prime[maxn];
bool vis[maxn];

void table(){
    int i,j;
    for(i=0;i<=100000;i++)
        prime[i].clear();
    for(i=2;i<=100000;i+=2)
        prime[i].push_back(2);
    for(i=3;i<=100000;i+=2){
        if(!vis[i]){
            for(j=i;j<=100000;j+=i){
                vis[j]=1;
                prime[j].push_back(i);
            }
        }
    }
}

int main()
{
    int i,j,a,n,c,m,T,kcase=1;
    table();
    sc(T);
    while(T--){
        int k;
        scanf("%d%d%d%d%d",&a,&n,&c,&m,&k);
        printf("Case %d: ",kcase++);
        if(k==0){
            puts("0");continue;
        }
        n/=k;m/=k;
        if(n==0 || m==0){
            puts("0");continue;
        }
        if(n>m)
            swap(n,m);
        LL res=m;
        for(i=2;i<=n;i++){
            res+=m-i;
            int lcm=1,cnt,Size=prime[i].size(),tot=(1<<Size);
            for(j=1;j<tot;j++){ //j从1开始
                lcm=1;cnt=0;
                for(int q=0;q<Size;q++){
                    if((j>>q)&1){
                        lcm*=prime[i][q];
                        if(lcm>m) break;
                        cnt++;
                    }
                }
                if(lcm>m) continue;
                if(cnt&1)
                    res-=(m/lcm)-(i)/lcm;
                else res+=(m/lcm)-(i)/lcm;
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}





