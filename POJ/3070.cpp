#include <stdio.h>
#include <math.h>
#include <string.h>
typedef __int64 ll;

const int maxn=10;

struct Matrix{
	int n,m,a[maxn][maxn];
	void clear(){n=m=0;memset(a,0,sizeof(a)); }
	Matrix operator + (const Matrix &b) const{
		Matrix tep;
		tep.n=n;tep.m=m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				tep.a[i][j]=(a[i][j]+b.a[i][j])%10000;
		return tep;
	}
	Matrix operator - (const Matrix &b) const{
		Matrix tep;
		tep.n=n;tep.m=m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				tep.a[i][j]=(a[i][j]-b.a[i][j])%10000;
		return tep;
	}
	Matrix operator * (const Matrix &b) const{
		Matrix tep;
		tep.clear();
		tep.n=n;tep.m=b.m;
		for(int i=0;i<n;i++)
			for(int j=0;j<b.m;j++)
				for(int k=0;k<m;k++){
					tep.a[i][j]+=a[i][k]*b.a[k][j];
					tep.a[i][j]%=10000;
				}
		return tep;
	}
};

int cal(ll n){
	Matrix t,e;
	t.n=t.m=2;
	t.a[0][0]=t.a[0][1]=t.a[1][0]=1;t.a[1][1]=0;
	e.n=e.m=2;
	e.a[0][0]=e.a[1][1]=1;e.a[1][0]=e.a[0][1]=0;
	while(n){
		if(n&1)
			e=e*t;
		t=t*t;
		n/=2;
	}
	return (e.a[0][0]+e.a[0][1])%10000;
}






int main()
{
	int i,ans;
	ll n;
	while(scanf("%I64d",&n)!=EOF){
		if(n<2){
			printf("%I64d\n",n);
			continue;
		}
		ans=cal(n-2);
		printf("%d\n",ans);
	}
	return 0;
}
