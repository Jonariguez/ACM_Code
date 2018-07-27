/****************
*PID:uva10692
*Auth:Jonariguez
*****************
用欧拉函数递归降幂。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=10000+10;
LL phi[maxn],a[12],n,m;

void table(){
    LL i,j;
    phi[1]=1;
    for(i=2;i<=10000;i++){
        if(!phi[i]){
            for(j=i;j<=10000;j+=i){
                if(!phi[j]) phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}

LL read(char *s){
    LL n=strlen(s),res=0;
    for(LL i=0;i<n;i++)
        res=res*10+(s[i]-'0');
    return res;
}

LL quick_pow(LL a,LL b,LL m){
    a=(a%m+m)%m;
    LL res=1;
    while(b){
        if(b&1) res=(res*a)%m;
        b/=2;
        a=(a*a)%m;
    }
    return res;
}

LL dfs(LL cur,LL MOD){
    if(MOD==1) return 1;    //当MOD=1时，上面的指数层%1=0，则直接返回0就是了，不用再递归了
    if(cur==n-1)
        return a[cur]%MOD;
    LL temp=dfs(cur+1,phi[MOD]);
    return quick_pow(a[cur],temp+phi[MOD],MOD);     //这里是temp+phi[MOD],而不是temp
}

int main()
{
    LL i,j,k=1;
    char str[10];
    table();
    while(scanf("%s",str) && str[0]!='#'){
        m=read(str);
        scanf("%lld",&n);
        for(i=0;i<n;i++) scanf("%lld",&a[i]);
        printf("Case #%lld: %lld\n",k++,dfs(0,m));
    }
    return 0;
}

