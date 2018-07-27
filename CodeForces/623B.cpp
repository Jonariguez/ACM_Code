/****************
*PID:623b div1
*Auth:Jonariguez
*****************
�����⣬��Ȼ������������µ�һ���������һ����
��ônum[1]��num[1]+-1��num[n]��num[n]+-1���������б���һ���������������
�����Ƿֽ�����������ô������������ٺ�����Щ������������һ��.
��f[i]Ϊ�����ҽ��е�iλ�ã�ÿ��ֻ����2�����򲻽��еĴ���
��g[j]Ϊ���ҵ�����е�jλ�ã�ͬ��
��ô��Ϊf[i]+g[j]+(j-i-1)*a
��(f[i]-i*a-a) + (g[j]+j*a)
ö��i��ǰ������ά����Сֵ������ö�٣�����������ұ߿϶������������
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
	for(i=1;i<=n+1;i++){     //�㵽n+1�Ǽ����˲��������ұߵ������
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

