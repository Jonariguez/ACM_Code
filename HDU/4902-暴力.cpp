/*
��˵�Ǳ��������Ǹ������ݷ�������
��̯���Ӷ��ܱ�֤����
������⣬�Ӻ���ǰ�Ҳ���1���ҵ�֮������ǰ��
�������ڵ�ǰi��û�õġ�
���Զ���n������ö��ÿ��λ���ϵ����һ��1����
����֮���2�������������С���ջʵ�֡�
���û��1��������ǳ�ֵa[i]
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
