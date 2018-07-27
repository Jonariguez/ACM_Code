#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef __int64 ll;

const int MOD=9901;
ll divi[10000][2],tot;

ll quick_mod(ll a,ll b){		//a^b%MOD
	ll res=1;
	a%=MOD;
	while(b){
		if(b&1) res=(res*a)%MOD;
		b/=2;
		a=(a*a)%MOD;
	}
	return res;
}

ll cal(int p,int n){
	if(n==0) return 1;
	if(n&1)
		return (1+quick_mod(p,n/2+1))*cal(p,n/2)%MOD;
	else
		return ((1+quick_mod(p,n/2+1))*cal(p,n/2-1)+quick_mod(p,n/2))%MOD;
}

void pre_solve(ll n){
	ll i;
	tot=0;
	for(i=2;i*i<=n;){
		if(n%i==0){
			divi[tot][0]=i;
			divi[tot][1]=0;
			do{
				n/=i;divi[tot][1]++;
			}while(n%i==0);
			tot++;
		}
		if(i==2) i++;
		else i+=2;
	}
	if(n>1){
		divi[tot][0]=n;divi[tot][1]=1;tot++;
	}
}

int main()
{
	ll A,B,i,res;
	while(scanf("%I64d%I64d",&A,&B)!=EOF){
		if(A==0){
			printf("0\n");continue;
		}
		if(A==1 || B==0){
			printf("1\n");continue;
		}
		pre_solve(A);
		res=1;
		for(i=0;i<tot;i++)
			divi[i][1]*=B;
		for(i=0;i<tot;i++){
			res=(res*cal(divi[i][0],divi[i][1]))%MOD;
		}
		printf("%I64d\n",res);
	}
	return 0;
}

