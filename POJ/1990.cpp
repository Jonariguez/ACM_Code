#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=20000+10;
ll bit0[maxn],bit1[maxn];   //bit0ά���������ĸ�����bit1ά���������ĺ�

struct pp
{
    ll x,v;
}s[maxn];

int cmp(const pp &x,const pp &y){
    return x.v<y.v;
}

void add(ll *bit,ll i,ll v){
    while(i<=20000){
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
    ll i,n,t,res;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
        scanf("%lld%lld",&s[i].v,&s[i].x);
    sort(s,s+n,cmp);        //��v����Ϳ��Ա����v[i],v[j]�Ĵ�С����
    res=0;
    for(i=0;i<n;i++){
        ll t1=sum(bit0,s[i].x),t2=sum(bit0,20000);
        ll d1=sum(bit1,s[i].x),d2=sum(bit1,20000);
        res+=(t1*s[i].x-d1+(d2-d1)-(t2-t1)*s[i].x)*s[i].v;  //�ͷֳ�ǰ����������
        add(bit0,s[i].x,1);
        add(bit1,s[i].x,s[i].x);
    }
    printf("%lld\n",res);
    return 0;
}





