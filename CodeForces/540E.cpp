/*
��ɢ��+BIT�������(����)
��������Ҫ�Ѿ������Ľ�����ת������
���λ�õĸı䣬�������λ�ñ��浽
һ������������ȥ�أ���ɢ��Ӧ����Լ
[1,4*n]��(��Ϊ�����2*n���㣬���ϵ����
֮�����Ҳ��ӳ���һ����)��Ȼ�����������
�а������[1,1e9]��Χ�ڵĽ���ת����
[1,4*n]��Ȼ��ֻ��ҪO(n)������ʣ�µĽ���
BIT������ԡ�
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
    int idx;    //idxλ�ã�����Դ�С
    ll v;       //v����ɢ��ÿ��λ�ö�Ӧ�ĵ�ĸ���
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
        for(i=tot;i>0;i--){   //ע��������һ�����ô���Ȼ��ѭ����������仰λ�ò��ܱ�
            add(s[i].idx,s[i].v);
            res+=sum(s[i].idx-1)*s[i].v;
        }
        printf("%I64d\n",res);
    }
    return 0;
}
