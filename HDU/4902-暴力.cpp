/*
虽说是暴力，但是根据数据分析，其
均摊复杂度能保证过。
逆向求解，从后往前找操作1，找到之后再往前的
操作对于当前i是没用的。
所以对于n个数，枚举每个位置上的最后一个1操作
和其之后的2操作，暴力就行。用栈实现。
如果没用1操作则就是初值a[i]
*/
#include <stdio.h>
#include <string.h>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
int a[maxn];
struct pp{
    int o,l,r;
    ll x;
}s[maxn];

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int i,j,n,q,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&q);
        for(i=1;i<=q;i++)
            scanf("%d%d%d%lld",&s[i].o,&s[i].l,&s[i].r,&s[i].x);
        for(i=1;i<=n;i++){
            stack<ll> S;
            int flag=0;
            for(j=q;j>0;j--){
                if(i>=s[j].l && i<=s[j].r){
                    S.push(s[j].x);
                    if(s[j].o==1){
                        flag=1;break;
                    }
                }
            }
            if(!flag)
                S.push((ll)a[i]);
            ll res=S.top();S.pop();
            while(!S.empty()){
                ll t=S.top();S.pop();
                if(res>t)
                    res=gcd(res,t);
            }
            printf("%lld ",res);
        }
        printf("\n");
    }
    return 0;
}
