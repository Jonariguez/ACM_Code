/*
离散化+BIT求逆序对(离线)
首先这题要把具体数的交换，转换成其
相对位置的改变，把输入的位置保存到
一个数组中排序去重，离散对应到大约
[1,4*n]中(因为最多有2*n个点，加上点与点
之间的数也会映射成一个点)，然后在这个区间
中把输入的[1,1e9]范围内的交换转换成
[1,4*n]，然后只需要O(n)交换，剩下的交给
BIT求逆序对。
*/
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
typedef __int64 ll;

const int maxn=100000+10;
ll bit[maxn*4],tot;
ll x[maxn],y[maxn],q[maxn*2];

struct pp{
    int idx;    //idx位置，即相对大小
    ll v;       //v是离散后每个位置对应的点的个数
}s[maxn];

void add(int i,ll v){
    while(i<=tot){
        bit[i]+=v;
        i+=i&(-i);
    }
}

ll sum(int i){
    ll res=0;
    while(i>0){
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}

map<ll,int> mp;

int main()
{
    int i,j,k,n,m;
    while(scanf("%d",&n)!=EOF){
        m=1;
        memset(bit,0,sizeof(bit));
        for(i=1;i<=n;i++){
            scanf("%I64d%I64d",&x[i],&y[i]);
            q[m++]=x[i];q[m++]=y[i];
        }
        sort(q+1,q+m);
        q[0]=tot=0;
        mp.clear();
        for(i=1;i<m;i++){
            if(q[i]==q[i-1]+1){
                s[++tot].idx=tot;s[tot].v=1;
                mp[q[i]]=tot;
            }else if(q[i]-q[i-1]>1){
                s[++tot].idx=tot;s[tot].v=(ll)q[i]-q[i-1]-1;
                s[++tot].idx=tot;s[tot].v=1;
                mp[q[i]]=tot;
            }
        }
        for(i=1;i<=n;i++){
            int a=mp[x[i]],b=mp[y[i]];
            pp t=s[a];s[a]=s[b];s[b]=t;
        }
        ll res=0;
        for(i=tot;i>0;i--){   //注意这里，最后一个不用处理，然后循环体里的两句话位置不能变
            add(s[i].idx,s[i].v);
            res+=sum(s[i].idx-1)*s[i].v;
        }
        printf("%I64d\n",res);
    }
    return 0;
}
