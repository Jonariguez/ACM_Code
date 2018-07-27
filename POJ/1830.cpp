
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define eps 1e-8
typedef __int64 ll;

const int maxn=10,maxm=10;

struct Matrix{
	int n,m,a[maxn][maxm];
	void clear(){
		n=m=0;
		memset(a,0,sizeof(a));
	}
	Matrix operator + (const Matrix &b) const{
		Matrix temp;
		temp.n=n;temp.m=m;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				temp.a[i][j]=(a[i][j]+b.a[i][j])%10000;
		return temp;
	}
	Matrix operator - (const Matrix &b) const{
		Matrix temp;
		temp.n=n;temp.m=m;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				temp.a[i][j]=(a[i][j]-b.a[i][j])%10000;
		return temp;
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

Matrix quick_pow(Matrix a,ll n){
	Matrix t=a,ans;
	int i,k,j;
	memset(ans.a,0,sizeof(ans.a));
	for(i=0;i<t.n;i++)
		ans.a[i][i]=1;
	while(n){
		if(n&1)
			ans=(ans*t);
		t=t*t;
		n/=2;
	}
	return ans;
}

int main()
{
	ll n;
	Matrix m,ans;
	m.a[0][0]=m.a[0][1]=m.a[1][0]=1;
	m.a[1][1]=0;
	while(scanf("%I64d",&n)!=EOF){
		ans=quick_pow(m,n-2);
		printf("%d\n",(ans.a[0][0]+ans.a[0][1])%10000);
	}
	return 0;
}



