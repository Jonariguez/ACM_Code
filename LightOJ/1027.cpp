/****************
*PID:lightoj1027
*Auth:Jonariguez
*****************
设d为走出迷宫的期望天数
那么第三个样例就是 d = 1/3*3+1/3*(6+d)+1/3*(9+d)

http://blog.csdn.net/danceonly/article/details/16824745
设一次选到正数的概率为P1，选到负数的概率为P2，选择的是正数
出去的平均时间为T1，选择的是负数出去的平均时间为T2，
设出去的期望时间为T，则有Y = P1 * T1 + P2 * (T2 + Y)。

解法二：
假设从A点可以走到B，C，D三点，且花费的代价分别为b，c，d，
概率分别为p1，p2，p3问从A走到F点的期望。
E（A）=p1（b+E(B））+p2（c+E（C））+p3（d+E（D））
结论：
假设  由状态A走到状态B的期望为E1，由状态B走到状态C的期望为E2
       那么由A状态走到C状态的期望为E1+E2；
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

const int maxn=100+10;
int a[maxn];

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int i,j,n,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int yes=1,neg=0,pos=0,sum=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=abs(a[i]);
            if(a[i]>0) pos++;
            else neg++;
        }
        printf("Case %d: ",kcase++);
        if(pos==0)
            puts("inf");
        else {
            int x=sum,y=pos;
            int g=gcd(x,y);
            printf("%d/%d\n",x/g,y/g);
        }
    }
    return 0;
}



