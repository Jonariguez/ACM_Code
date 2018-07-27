/****************
*PID:hdu5036
*Auth:Jonariguez
*****************
用传递闭包求出某个点的“联通情况”，即直接或者
间接和某个点相连的点的个数
O(n^3)的floyd，用bitset优化才行。
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
#include <bitset>
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
bitset<maxn> key[maxn];

int main()
{
    int i,j,n,t,k,T,kcase=1;
    sc(T);
    while(T--){
        sc(n);
        for(i=1;i<=n;i++){
            key[i].reset();
            key[i][i]=true;
        }
        for(i=1;i<=n;i++){
            sc(k);
            while(k--){
                sc(t);
                key[i][t]=true;
            }
        }
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(key[j][i])   //意思是：如果j能到i，那么i所能到的门，j就都能到了。
                    key[j]|=key[i];
        double res=0;
        for(i=1;i<=n;i++){
            int num=0;
            for(j=1;j<=n;j++)   //注意这里是计算有多少j能到i，而不是key[i].count()计算i能到多少j
                if(key[j][i]) num++;
            res+=1.0/num;
        }
        printf("Case #%d: %.5f\n",kcase++,res);
    }
    return 0;
}


