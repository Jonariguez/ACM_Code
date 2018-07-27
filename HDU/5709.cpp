/****************
*PID:hdu5709
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;
const int maxm=10000000;
//T1[]:map(��ȣ�����),T2[]:map(��ɫ�����)
int T1[maxn];  //T1[x]ά����xΪ���ڵ�������У������[l,r]�Ľڵ������ͬ����ɫ�ж��ֵĻ���ֻ���������С����һ����
int T2[maxn];  //T2[x]ά����xΪ���ڵ�������У�ÿ����ɫ����С��ȡ�
int tot,L[maxm],R[maxm],v[maxm]; //��̬�߶����ļӵ㣬L[x],R[x],V[x]�ֱ��ʾ�����������͵�ǰ�ڵ��ֵ
int C[maxn],d[maxn],par[maxn],n;

int Insert(int p,int val,int k,int l,int r){
    int y=++tot;
    v[y]=v[k]+val;
    if(l==r) return y;
    int m=(l+r)/2;
    if(p<=m){
        L[y]=Insert(p,val,L[k],l,m);
        R[y]=R[k];
    }else {
        L[y]=L[k];
        R[y]=Insert(p,val,R[k],m+1,r);
    }
    return y;
}

int merge1(int x,int y,int l,int r){
    if(x==0 || y==0) return x+y;
    int z=++tot;
    v[z]=v[x]+v[y];
    if(l==r)
        return z;
    int m=(l+r)/2;
    L[z]=merge1(L[x],L[y],l,m);
    R[z]=merge1(R[x],R[y],m+1,r);
    return z;
}
//��Ϊ�ںϲ�ʱ�������Ҫɾ���������������Ⱥϲ���T1�����Ժϲ�T1ʱû�д����ظ����ϲ�T2ʱҪ����T2��T1��ȥɾ��
int merge2(int x,int y,int fa,int l,int r){        //����Ҫ��¼x��y�ϲ�֮����T1�еĸ���(����Ҫȥ�����������ɾ��)
    if(x==0 || y==0) return x+y;
    int z=++tot;
    if(l==r){   //l==rʱ��������ɫΪlʱ��Ӧ����ȣ�����Ҫȡx��y�����߶��������С����һ����
        if(v[x]<v[y]){  //��Ҫ��T1��ɾ����ȴ����һ����һ���ڵ㡣����Ϊֻ�������С��������һ����ȻҪ��ȥ1��
            v[z]=v[x];
            T1[fa]=Insert(v[y],-1,T1[fa],1,n);  //�ѽϴ����v[y]��ȥ1
        }else {
            v[z]=v[y];
            T1[fa]=Insert(v[x],-1,T1[fa],1,n);
        }
        return z;
    }
    int m=(l+r)/2;
    L[z]=merge2(L[x],L[y],fa,l,m);  //������׽ڵ�Ҫһֱ��fa�Ŷԡ�
    R[z]=merge2(R[x],R[y],fa,m+1,r);
    return z;
}

int ask(int a,int b,int k,int l,int r){
    if(a<=l && r<=b)
        return v[k];
    int m=(l+r)/2,res=0;
    if(a<=m)
        res+=ask(a,b,L[k],l,m);
    if(b>m)
        res+=ask(a,b,R[k],m+1,r);
    return res;
}


int main()
{
    int i,j,m,T;
    sc(T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++) sc(C[i]);
        for(i=2;i<=n;i++) sc(par[i]);
        for(i=1;i<=n;i++)
            d[i]=d[par[i]]+1;
        tot=1;
        for(i=1;i<=n;i++){
            T1[i]=Insert(d[i],1,1,1,n);     //��d[i]�����+1
            T2[i]=Insert(C[i],d[i],1,1,n);  //��C[i]��ɫ��+d[i]
        }
        //��������merge,�Ե�����,��ÿһ���ڵ���丸�׺ϲ����Ⱥϲ�T1[]
        for(i=n;i>1;i--){
            T1[par[i]]=merge1(T1[par[i]],T1[i],1,n);
            T2[par[i]]=merge2(T2[par[i]],T2[i],par[i],1,n);
        }
        int last=0;
        while(m--){
            int x,D;
            scanf("%d%d",&x,&D);
            x^=last;D^=last;
            D+=d[x];
            if(D>n) D=n;
            printf("%d\n",(last=ask(1,D,T1[x],1,n)));
        }
    }
    return 0;
}


