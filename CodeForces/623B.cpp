/****************
*PID:623b div1
*Auth:Jonariguez
*****************
由题意，显然至少数组会留下第一个数或最后一个数
那么num[1]、num[1]+-1、num[n]、num[n]+-1这六个数中必有一个存在题解数组里
将他们分解质因数，那么题解数组里至少含有这些质因数的其中一个.
记f[i]为从左到右进行到i位置，每次只进行2操作或不进行的代价
记g[j]为从右到左进行到j位置，同上
那么答案为f[i]+g[j]+(j-i-1)*a
即(f[i]-i*a-a) + (g[j]+j*a)
枚举i，前者括号维护最小值，后者枚举，这样算的是右边肯定保留的情况。
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
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int maxn=1000000+5;
const LL INF=1e16;
int a[maxn],n,A,B;
LL f[maxn],g[maxn];
vector<int> p;

void get(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			p.push_back(i);
			while(n%i==0) n/=i;
		}
	}
	if(n!=1)
		p.push_back(n);
}

LL solve(int x){
	f[0]=0;
	int i;
	for(i=1;i<=n;i++){
		f[i]=INF;
		if(a[i]%x==0) f[i]=f[i-1];
		else if((a[i]+1)%x==0 || (a[i]-1)%x==0) f[i]=f[i-1]+B;
	}
	g[n+1]=0;
	for(i=n;i>=1;i--){
		g[i]=INF;
		if(a[i]%x==0) g[i]=g[i+1];
		else if((a[i]+1)%x==0 || (a[i]-1)%x==0) g[i]=g[i+1]+B;
	}
	LL res=INF,mv=-A;
	for(i=1;i<=n+1;i++){     //算到n+1是加上了不保留最右边的情况。
		res=min(res,g[i]+(LL)i*A+mv);
		mv=min(mv,f[i]-(LL)(i+1)*A);
	}
	//for(i=1;i<=n;i++)
   //     res=min(res,f[i]+(LL)(n-i)*A);
	return res;
}

int main()
{
	int i,j;
	while(scanf("%d%d%d",&n,&A,&B)!=EOF){
		p.clear();
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=-1;i<=1;i++){
			get(a[1]+i);get(a[n]+i);
		}
		sort(p.begin(),p.end());
		p.erase(unique(p.begin(),p.end()),p.end());
		LL res=INF;
		for(i=0;i<p.size();i++)
			res=min(res,solve(p[i]));
		printf("%I64d\n",res);
	}
	return 0;
}

