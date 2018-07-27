/*
phi[n]=(p1-1)*p1^k1 * (p2-1)*p2^k2 *..* (pa-1)*pa^ka

可知，n中的所有素因子p必须满足phi(n)%(p-1)==0这一条件(#)，
换句话说就是：找出所有满足phi_n%(p-1)==0的p，那么用p
构造出来n。
但也不能说是对phi[n](下phi_n)素数分解，因为ki可以为0,
所以我们就对每个素数p判断是否有phi_n%(p-1)==0，成立的
p就记录到f[]中，后面用f[]来求n。（所以dfs里面的sum都是
乘以f[cur]呢，而不是f[cur]-1）
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000000;
bool vis[10005];
vector<int> prime,f;

void prime_table(){
    int i,j;
    memset(vis,0,sizeof(vis));
    for(i=2;i<=10000;i++)
        if(!vis[i]){
            prime.push_back(i);
            for(j=i*i;j<=10000;j+=i)
                vis[j]=1;
        }
}

void divide(int phi_n){
    f.clear();              //
    for(int i=0;i<prime.size() && (prime[i]-1)*(prime[i]-1)<=phi_n;i++) //
        if(phi_n%(prime[i]-1)==0)
            f.push_back(prime[i]);
}

bool judge(int n){
    int i;
    for(i=0;i<prime.size() && prime[i]*prime[i]<=n;i++)
        if(n%prime[i]==0) return false;
    for(i=0;i<f.size();i++)
        if(f[i]==n && vis[i]==1) return false;
    return true;
}

/*
我们预处理的是10000以内的素数p，但phi_n很大，可能会存在一个大于10000的素因子！
这样的话，在dfs时，当用尽所有的f[]时，剩下的now不为1的话，说明剩下的now就是
一个(p-1)的形式,即p=now+1，所以我们坚查p是不是一个素数且是前面没用过的素数即可
①是素数，且前面没用过，那么这就是一个新的p，是需要把这个乘进结果sum里去构造n就对了
②是素数，但前面用过了，既然用过，也就是已经满足了上面(#)要求，就不要再多乘一个p了，
因为题目要求n尽量小。
③不是素数，这种情况说明前面的一系列构造都不行，因为前面10000以内的素数都试除完了，
如果不剩最好，说明构造完成；如果剩了，也应该是一个素数，然后再拿这个素数去构造n，
但是不是素数的话就是错了，return回上一层。
*/
int res;

void dfs(int cur,int now,int sum){
    if(cur==f.size()){
        if(now==1) res=min(res,sum);
        else if(judge(now+1)){
            sum*=(now+1);
            res=min(res,sum);
        }
        return ;
    }
    dfs(cur+1,now,sum);
    if(now%(f[cur]-1)) return ;
    vis[cur]=1;
    now/=(f[cur]-1);        //注意这里是用p-1
    sum*=f[cur];
    dfs(cur+1,now,sum);
    while(now%f[cur]==0){   //而这里用p
        now/=f[cur];
        sum*=f[cur];        //既然是让结果n尽量小，那么为什么还要多次使用f[cur]呢？ 因为我们只知道
        dfs(cur+1,now,sum); //在结果中含有f[cur]这个素因子，但具体几个不知道，所以要多次尝试，来找到正确
    }                       //的结果，这也是dfs的使用方法啊
    vis[cur]=0;         //既然vis是用来标记p是否被用的，那么就在p被用之前标1，用完之后标0
}

int main()
{
    int i,j,kcase=1;
    int phi_n;
    prime_table();
    while(scanf("%d",&phi_n),phi_n){
        divide(phi_n);
        res=200000000;
        memset(vis,0,sizeof(vis));
        dfs(0,phi_n,1);
        printf("Case %d: %d %d\n",kcase++,phi_n,res);
    }
    return 0;
}
