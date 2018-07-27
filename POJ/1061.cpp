#include <stdio.h>
#include <math.h>
#include <string.h>
typedef __int64 ll;

void Exgcd(ll a,ll b,ll &d,ll &x,ll &y){
	if(b==0){
		x=1;y=0;d=a;return ;
	}
	Exgcd(b,a%b,d,y,x);
	y-=(a/b)*x;
}

int main()
{
	ll x,y,n,m,l,c,d,a,b,g;
	scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&l);
	c=x-y;
	a=n-m;
	b=l;
	Exgcd(a,b,d,x,y);
	if(c%d){
		printf("Impossible\n");
		return 0;
	}
	ll t=b/d;
	x=x*(c/d);
	x=(x%t+t)%t;
	printf("%I64d\n",x);
	return 0;
}
