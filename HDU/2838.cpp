/*
逆序对
两个BIT：一个维护逆序对(离线倒序)，一个维护前缀和。
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
ll bit[maxn],bit1[maxn],a[maxn],n;

void add(ll *bit,ll i,ll v){
    while(i<=n){
        bit[i]+=v;
        i+=i&(-i);
    }
}

ll sum(ll *bit,ll i){
    ll res=0;
    while(i>0){
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}

int main()
{
    int i,j;
    ll res;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    res=0;
    for(i=n;i>0;i--){
        res+=sum(bit,a[i])*a[i]+sum(bit1,a[i]);
        add(bit,a[i],1);
        add(bit1,a[i],a[i]);
    }
    printf("%lld\n",res);
    return 0;
}
