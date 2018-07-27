/****************
*PID:474e div2
*Auth:Jonariguez
*****************
dp+线段树+离散化
线段树以高度为下标，dp值为值建树。
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

const int maxn=100000+5;
const LL INF=1e17;

int dp[maxn],pre[maxn],tot;
LL a[maxn];
map<LL,int> mp;
vector<LL> p;

struct node{
    int DP,id;
    bool operator < (const node &r) const {
        return DP<r.DP;
    }
};

struct Segment{
	node sum[maxn*4];
	void pushUp(int k){
		int lc=k*2,rc=k*2+1;
		sum[k]=max(sum[lc],sum[rc]);
	}
	void build(int k,int l,int r){
		if(l==r){
			sum[k].DP=0;sum[k].id=0;
			return ;
		}
		int m=(l+r)/2;
		build(k*2,l,m);
		build(k*2+1,m+1,r);
        pushUp(k);
	}
	void update(int p,int v,int id,int k,int l,int r){
		if(l==r){
            if(sum[k].DP<v){
                sum[k].DP=v;sum[k].id=id;
            }
			return;
		}
		int m=(l+r)/2;
		if(p<=m)
			update(p,v,id,k*2,l,m);
		else update(p,v,id,k*2+1,m+1,r);
		pushUp(k);
	}
	node ask(int a,int b,int k,int l,int r){
		if(a>b){
			node u;
			u.DP=0;u.id=0;
			return u;
		}
		if(a<=l && r<=b)
			return sum[k];
		int m=(l+r)/2;
		node res;
		res.DP=0;res.id=0;
		if(a<=m)
            res=max(res,ask(a,b,lson));
		if(b>m)
            res=max(res,ask(a,b,rson));
		return res;
	}
}tree;

void print(int u){
	if(pre[u]) print(pre[u]);
	printf("%d ",u);
}

int get(LL x){
	return upper_bound(p.begin(),p.end(),x)-p.begin()-1;
}


int getL(LL x){
    return lower_bound(p.begin(),p.end(),x+1)-p.begin()-1;
}

int getR(LL x){
    return upper_bound(p.begin(),p.end(),x-1)-p.begin();
}

int main()
{
	int i,j,n,d;
	while(scanf("%d%d",&n,&d)!=EOF){
		p.clear();
		mp.clear();
		p.push_back(0);
		LL minv=INF,maxv=0;
		for(i=1;i<=n;i++){
			scanf("%I64d",&a[i]);
			minv=min(minv,a[i]);
			maxv=max(maxv,a[i]);
			p.push_back(a[i]);
		}
		sort(p.begin(),p.end());
		p.erase(unique(p.begin(),p.end()),p.end());
		int m=p.size()-1;
		tot=m;
		p.push_back(1e17);
		memset(pre,0,sizeof(pre));
		tree.build(1,1,m);
		dp[1]=1;
		int id=get(a[1]);
		pre[1]=0;
		tree.update(id,1,1,1,1,m);
		int res=1,idx=1;
		for(i=2;i<=n;i++){
			node u;
			u.DP=0;u.id=0;
			if(a[i]-d>=minv){
				id=getL(a[i]-d);
				node temp=tree.ask(1,id,1,1,m);
				u=max(u,temp);
			}
			if(a[i]+d<=maxv){
				id=getR(a[i]+d);
				node temp=tree.ask(id,m,1,1,m);
				u=max(u,temp);
			}
			dp[i]=u.DP+1;
			pre[i]=u.id;
			id=get(a[i]);
			tree.update(id,dp[i],i,1,1,m);
			if(res<dp[i]){
				res=dp[i];idx=i;
			}
		}
		printf("%d\n",res);
		print(idx);
		puts("");
	}
	return 0;
}



