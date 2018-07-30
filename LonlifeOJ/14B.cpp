/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("d",&x,&y)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#define MP make_pair
#define X first
#define Y second
#define PI acos(-1.0)
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
const int MOD=1e9+7;

int a[maxn];

vector<int> vec;
map<int,int> mp;

struct node{
    int op,x;
}s[maxn];

typedef struct Segment{
    int sum[maxn*4],Set[maxn*4];
    void pushUp(int k){
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void pushDown(int k,int l,int r){
        if(Set[k]==0){
            sum[k*2]=sum[k*2+1]=0;
            Set[k*2]=Set[k*2+1]=0;
        }
        if(Set[k]>0){
            int m=(l+r)/2;
            sum[k*2]=Set[k]*(m-l+1);
            sum[k*2+1]=Set[k]*(r-(m+1)+1);
            Set[k*2]=Set[k*2+1]=Set[k];
        }
        Set[k]=-1;
    }
    void build(int k,int l,int r){
        sum[k]=0;
        Set[k]=-1;
        if(l==r)
            return ;
        int m=(l+r)/2;
        build(lson);
        build(rson);
    }
    void update(int a,int b,int v,int k,int l,int r){
        if(a<=l && r<=b){
            Set[k]=v;
            sum[k]=v*(r-l+1);
            return ;
        }
        pushDown(k,l,r);
        int m=(l+r)/2;
        if(a<=m)
            update(a,b,v,lson);
        if(b>m)
            update(a,b,v,rson);
        pushUp(k);
    }
    int ask1(int x,int k,int l,int r){
        if(l==r)
            return l;
        int m=(l+r)/2,res=1;
        pushDown(k,l,r);
        if(sum[k*2]>=x)
            res=ask1(x,lson);
        else res=ask1(x-sum[k*2],rson);
        pushUp(k);
        return res;
    }
    int ask2(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        int m=(l+r)/2;
        int res=0;
        pushDown(k,l,r);
        if(a<=m)
            res+=ask2(a,b,lson);
        if(b>m)
            res+=ask2(a,b,rson);
        pushUp(k);
        return res;
    }
   /* int ask3(int p,int k,int l,int r){
        if(l==r)
            return sum[k];
        int m=(l+r)/2,res=0;
        pushDown(k,l,r);
        if(p<=m)
            res=ask3(p,lson);
        if(p>m)
            res=ask3(p,rson);
        pushUp(k);
        return res;
    }*/
}Tree;

Tree tree;

int main()
{
    int i,j,m;
    vec.clear();
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%d%d",&s[i].op,&s[i].x);
        if(s[i].op==1 || s[i].op==2 || s[i].op==3 || s[i].op==5)
            vec.push_back(s[i].x);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    int n=vec.size();
    mp.clear();
    for(i=1;i<=n;i++){
        mp[vec[i-1]]=i;
        a[i]=vec[i-1];
    }
    tree.build(1,1,n);
    int cnt=0;
    for(i=1;i<=m;i++){
        if(s[i].op==1){
            int p=mp[s[i].x];
            int cur=tree.ask2(p,p,1,1,n);
            tree.update(p,p,cur+1,1,1,n);
            cnt++;
        }else if(s[i].op==2){
            int p=mp[s[i].x];
            int sum=0;
            if(p>1){
                sum=tree.ask2(1,p-1,1,1,n);
                tree.update(1,p-1,0,1,1,n);
            }
            int cur=tree.ask2(p,p,1,1,n);
            tree.update(p,p,cur+sum,1,1,n);
        }else if(s[i].op==3){
            int p=mp[s[i].x];
            int sum=0;
            if(p<n){
                sum=tree.ask2(p+1,n,1,1,n);
                tree.update(p+1,n,0,1,1,n);
            }
            int cur=tree.ask2(p,p,1,1,n);
            tree.update(p,p,cur+sum,1,1,n);
        }else if(s[i].op==4){
            if(s[i].x>cnt)
                s[i].x=cnt;
            if(s[i].x<1)
                s[i].x=1;
            printf("%d\n",a[tree.ask1(s[i].x,1,1,n)]);
        }else {
            int p=mp[s[i].x];
            if(p<=1)
                printf("0\n");
            else
                printf("%d\n",tree.ask2(1,p-1,1,1,n));
        }
    }
    return 0;
}

