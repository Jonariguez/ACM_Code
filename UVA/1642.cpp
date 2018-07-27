/*
很巧，思想和单调队列很像
枚举ai，保存从[0,i-1]到i得gcd值，和下标起点，如果
gcd值相等的，保存最小的下标值，因为gcd值最多有log(i)
个，所以复杂度不高。每次遍历前面log(i)个gcd值来更新
最大值最为答案，更新晚完之后，用ai与前面的全部gcd值
做gcd()，来更新前面的gcd值，复杂度O(log(n)^2)
总复杂度：O(nlog(n)^2)
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
ll a[maxn];

struct pp{
    ll g;
    int id;
}s[maxn];

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int i,j,n,tot,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        ll res=0;
        int tot=0;
        for(i=0;i<n;i++){
            ll x=a[i];
            s[tot].id=i;s[tot++].g=x;
            int len=tot;
            tot=0;
            for(j=0;j<len;j++){     //更新gcd表
                ll g=gcd(s[j].g,x);
                if(tot==0 || g!=s[tot-1].g){
                    s[tot].g=g;s[tot].id=s[j].id;tot++;
                }
            }
            for(j=0;j<tot;j++)      //更新答案
                res=max(res,s[j].g*(i-s[j].id+1));
        }
        printf("%lld\n",res);
    }
    return 0;
}
