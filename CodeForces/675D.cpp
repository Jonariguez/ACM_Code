/****************
*PID:675d div2
*Auth:Jonariguez
*****************
map<int,int> mp[a[i]]=i
很明显，对于每个a[i]，在mp中二分，找到的位置p(tree[p])，那么现在的
a[i]应该是二叉排序树的中序遍历之后，位置p的前驱，这样就是找位置p的
左儿子的最右子孙(如果没有左儿子则直接就是左儿子)
找最右子孙可以用并查集快速维护。
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
#include <utility>
#include <iterator>
#include <stdlib.h>
using namespace std;
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;
int par[maxn],res[maxn],a[maxn];

struct node{
    int val,l,r,id;
}tree[maxn];

map<int,int> mp;

int find(int x){
    if(tree[x].r==0)
        return x;
    return par[x]=find(tree[x].r);
}

int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    mp[a[1]]=1;
    tree[1].val=a[1];
    tree[1].l=tree[1].r=0;
    par[1]=1;
    for(i=2;i<=n;i++){
        map<int,int>::iterator t=mp.lower_bound(a[i]);
        if(t==mp.end()){
            int x=mp.rbegin()->first;
            int y=mp.rbegin()->second;
            res[i]=x;
            tree[y].r=i;
            tree[i].val=a[i];
            tree[i].l=tree[i].r=0;
        }else {
            int x=t->first; //val
            int y=t->second;    //id
            if(tree[y].l==0){
                res[i]=tree[y].val;
                tree[y].l=i;
            }else {
                int temp=tree[y].l;
                temp=find(temp);
                tree[temp].r=i;
                res[i]=tree[temp].val;
            }
        }
        tree[i].val=a[i];
        par[i]=i;
        mp[a[i]]=i;
    }
    for(i=2;i<=n;i++)
        printf("%d ",res[i]);
    return 0;
}

