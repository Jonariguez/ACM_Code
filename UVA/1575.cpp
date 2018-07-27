/****************
*ID:uva1575
*Auth:Jonariguez
*****************
设f(k)=n
则对k素数分解，k=p1^k1 * p2^k2 *...* ps^ks
那么n就应该是：
sigma{ki}!/(k1!*k2!*..*ks!)             (#) (该公式能够用组合数加速)
这就是有重复元素的全排列个数。
先打表，然后枚举每个素数的次数，构造k和n，然后记录答案到res中.

用组合数加速(#) 考虑组合数的表达式:C(n,k) = n!/(k!*(n-k)!)
假如在sigma{ki}!/(k1!*k2!*..*ks!)里增加一个kr,且kr=2，则sigma会增加2，下面分母也会多一项2！
不用重新计算，直接在原来的式子上乘上C(sigma+2,2),则：
sigma{ki}!/(k1!*k2!*..*ks!) * (sigma+2)!/(sigma!*2!)    约分即可
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;

const ULL M=(1ULL<<63);
vector<ULL> prime;
bool vis[102];
ULL c[65][65];
map<ULL,ULL> res;

void prime_table(){
    ULL i,j;
    memset(vis,0,sizeof(vis));
    for(i=2;i<=100;i++)
        if(!vis[i]){
            prime.push_back(i);
            for(j=i*i;j<=100;j+=i)
                vis[j]=1;
        }
}

void comb_table(){
    int i,j;
    for(i=0;i<=62;i++){
        for(j=0;j<=i;j++)
            if(j==0 || j==i)
                c[i][j]=1ULL;
            else if(c[i-1][j]<M && c[i-1][j-1]<M)
                c[i][j]=c[i-1][j]+c[i-1][j-1];
            else c[i][j]=M;
    }
}

/*f(k)=n    res[n]=k
cur 当前素数表prime指针，
k   用前cur个素数构造出来的数k
n   f(k)=n
sigma   上面(#)式中的sigma(ki),如果sigma有值，说明已经构造出来一对k n了
*/
void dfs(int cur,ULL k,ULL n,int sigma){    //注意sigma的初始要是0，而不是1
    if(sigma){
        int cnt=res.count(n);
        if(cnt==0 || cnt && k<res[n])
            res[n]=k;
    }
    ULL x=k;
    for(int i=1;prime[cur]<=M/x;i++){       //尝试k里添加素因子prime[cur]
        x*=prime[cur];
        if(c[sigma+i][i]<=M/n)        //这一步是往上(大)构造n，所以要判断n*c[sigma][i]是否超范围
            dfs(cur+1,x,n*c[sigma+i][i],sigma+i);
    }
}

int main()
{
    prime_table();
    comb_table();
    res.clear();
    dfs(0,1,1,0);
    ULL n;
    while(scanf("%llu",&n)!=EOF)
        printf("%llu %llu\n",n,res[n]);
    return 0;
}
