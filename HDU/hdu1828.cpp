/****************
*PID:hdu1828
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

const int maxn=10000+10;
const int off=10001;

struct line{
    int x,y1,y2;
    bool left;
    bool operator <(const line &r) const{
        if(x==r.x)
            return left>r.left; //�����������������ص�����ʵ���������ܳ���ģ���ͨ���ȼ�leftΪtrue���߶�
        return x<r.x;                   //���ɷ��ϳ���ʵ����һ�㡣
    }
}L[maxn*2];

typedef struct Segment{  //��������ƫ����10001����ô�������ֵΪ20000��Ȼ����*4
    int sum[maxn*8],L[maxn*8],R[maxn*8],cnt[maxn*8],cover[maxn*8];
    void pushUp(int k,int l,int r){
        int lc=k*2,rc=k*2+1;
        if(cover[k]){
            sum[k]=r-l+1;   //����
            L[k]=R[k]=1;    //����������
            cnt[k]=1;       //�߶εĶ˵�����ò��Ӧ��Ҳ����ȫ�ָ�����2���ɡ���
        }else if(l==r){
            sum[k]=L[k]=R[k]=cnt[k]=0;
        }else {
            sum[k]=sum[lc]+sum[rc];
            cnt[k]=cnt[lc]+cnt[rc];
            if(L[rc] && R[lc])
                cnt[k]--;
            L[k]=L[lc];R[k]=R[rc];
        }
    }
    void build(int k,int l,int r){
        sum[k]=0;L[k]=R[k]=cover[k]=cnt[k]=0;
        if(l==r)
            return ;
        int m=(l+r)/2;
        build(lson);
        build(rson);
    }
    void Insert(int a,int b,int k,int l,int r){
        if(a<=l && r<=b){
            cover[k]++;
            pushUp(k,l,r);
            return ;
        }
        int m=(l+r)/2;
        if(a<=m)
            Insert(a,b,lson);
        if(b>m)
            Insert(a,b,rson);
        pushUp(k,l,r);
    }
    void Delete(int a,int b,int k,int l,int r){
        if(a<=l && r<=b){
            cover[k]--;
            pushUp(k,l,r);
            return ;
        }
        int m=(l+r)/2;
        if(a<=m)
            Delete(a,b,lson);
        if(b>m)
            Delete(a,b,rson);
        pushUp(k,l,r);
    }
}Tree;

Tree tree;

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        if(n==0){
            puts("0");continue;
        }
        int x1,x2,y1,y2,tot=0,m=0;
        for(i=1;i<=n;i++){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            y1+=off;
            y2+=off;
            tot++;
            L[tot].x=x1;
            L[tot].y1=y1;
            L[tot].y2=y2;
            L[tot].left=true;
            tot++;
            L[tot].x=x2;
            L[tot].y1=y1;
            L[tot].y2=y2;
            L[tot].left=false;
            m=max(m,y2);
        }
        sort(L+1,L+tot+1);
        tree.build(1,1,m);
        int res=0,temp=0;
        for(i=1;i<=tot;i++){
            if(L[i].left)
                tree.Insert(L[i].y1,L[i].y2-1,1,1,m);
            else tree.Delete(L[i].y1,L[i].y2-1,1,1,m);
            if(i!=tot)
                res+=2*tree.cnt[1]*(L[i+1].x-L[i].x); //���Ϻ�ߵĳ��ȡ�
            res+=abs(tree.sum[1]-temp);     //ɨ���ߵ�ÿ�������ƶ���Ӧ���ۼӵ����ߵĳ���Ӧ���ǣ����������߼ӵ�
            temp=tree.sum[1];               //�߶�����֮���߶��������ߵĳ��ȵı仯����
        }
        pfn(res);
    }
    return 0;
}



