#include <stdio.h>
#include <string.h>
#include <math.h>
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
	ll a,b,c,d,g,k,x,y;
	while(scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&k)!=EOF){
		if(a+b+c+k==0) break;
		ll temp=c;
		c=b-a;
		a=temp;
		b=(ll)pow(2,k);
		Exgcd(a,b,g,x,y);
		if(c%g){
			printf("FOREVER\n");
			continue;
		}
		x=((x*c/g)%(b/g)+(b/g))%(b/g);
		printf("%I64d\n",x);
	}
	return 0;
}



