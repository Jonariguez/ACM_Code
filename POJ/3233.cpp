#include <stdio.h>
#include <string.h>

const int maxn=33;

typedef struct pp{
	int m[maxn][maxn];
}Matrix;

int n,MOD;
Matrix e;

Matrix add(Matrix a,Matrix b){
	int i,j;
	Matrix t;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			t.m[i][j]=a.m[i][j]+b.m[i][j];
			t.m[i][j]%=MOD;
		}
	return t;
}

Matrix multi(Matrix a,Matrix b){
	Matrix t;
	memset(t.m,0,sizeof(t.m));
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k=0;k<n;k++){
				t.m[i][j]+=(a.m[i][k]*b.m[k][j]);
				t.m[i][j]%=MOD;
			}
	return t;
}

Matrix quick_pow(Matrix a,int b){
	Matrix e,t;
	t=a;
	memset(e.m,0,sizeof(e.m));
	int i;
	for(i=0;i<n;i++) e.m[i][i]=1;
	while(b){
		if(b&1)
			e=multi(e,t);
		b/=2;
		t=multi(t,t);
	}
	return e;
}

Matrix cal(Matrix a,int k){
	if(k==1) return a;
	Matrix temp1,temp2;
	temp1=cal(a,k/2);
	temp2=quick_pow(a,(k+1)/2);
	if(k&1){
		temp1=multi(add(temp2,e),temp1);
		return add(temp1,temp2);
	}
	else 
		return multi(add(temp2,e),temp1);
}

int main()
{
	int i,j,k;
	Matrix a;
	scanf("%d%d%d",&n,&k,&MOD);
	memset(e.m,0,sizeof(e.m));
	for(i=0;i<n;i++)
		e.m[i][i]=1;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a.m[i][j]);
	Matrix t;
	t=cal(a,k);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d ",t.m[i][j]);
		printf("\n");
	}
	return 0;
}