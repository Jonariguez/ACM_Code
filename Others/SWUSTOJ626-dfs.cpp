/****************
*PID:SWUSTOJ626
*Auth:Jonariguez
*****************
迭代加深搜索
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
int maxd,ok;
ll res[maxn],v[maxn];
ll A,B;

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

//返回满足a/b>=1/c的最小的c，转换一下得：c>=b/a(向上取整)
ll get_first(ll a,ll b){
    return (b+a-1)/a;
}

bool better(int d){
    int i;
    for(i=0;i<=d;i++)
        if(v[i]!=res[i])    //在目前构造的分数和目前已经得到的答案中如果有不一样的，则通过这个不一样的来判断哪个
            return res[i]==-1 || res[i]>v[i];   //更优，那么如果res[i]还没更新，或v[i]比res[i]要小，则v是更优的
    return false;
}

//d:当前深度，f:分母不能小于f， 剩下的分数之和应该等于a/b
bool dfs(int d,int f,ll a,ll b){
    if(d==maxd){
        if(b%a) return false;       //搜到最后一层剩下的a/b应该是埃及分数(a/b约分后分子为1)才符合
        v[d]=b/a;             //记录结果
        if(better(d))       //如果目前构造的更优，则更新答案res
            memcpy(res,v,sizeof(ll)*(d+1));
        return true;
    }
    bool yes=false;
    f=max(f,(int)get_first(a,b));
    for(int i=f;;i++){
        int D=maxd-d+1;
        if(D*b<=i*a) break;         //如果剩下的(maxd-d+1)个分数全部是1/i依然小于a/b,那
        ll aa=a*f-b,bb=b*f;                 //么i增大了就更不可能到a/b,剪枝
        ll g=gcd(aa,bb);
        v[d]=i;                 //记录当前分数，并约分
        if(dfs(d+1,i+1,aa/g,bb/g))
            yes=true;
    }
    return yes;
}

int main()
{
    int i,j;
    ll g;
    scanf("%lld/%lld",&A,&B);
    g=gcd(A,B);
    A/=g;B/=g;
    if(A==1){
        printf("1/%lld\n",B);
        return 0;
    }
    memset(v,0,sizeof(v));
    ok=0;

    for(maxd=1;;maxd++){        //枚举深度
        memset(res,-1,sizeof(res));
        if(dfs(0,get_first(A,B),A,B)){
            ok=1;break;
        }
    }
    if(ok){
        printf("1/%lld",res[0]);
        for(int i=1;i<=maxd;i++)
            printf(" + 1/%lld",res[i]);
        printf("\n");
    }
    return 0;
}
