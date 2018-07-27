#include <stdio.h>
#include <math.h>
#include <string.h>
typedef __int64 ll;

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

ll a[1100],b[1100];
ll vis[11000];

int main()
{
	ll n,i,t,k;
	ll lcm,g;
	memset(vis,0,sizeof(vis));
	scanf("%I64d",&n);
	k=0;
	for(i=0;i<n;i++){
		scanf("%I64d",&t);
		if(vis[t]==0){
			a[k++]=t;
			vis[t]=1;
		}
	}
	ll t1,t2,t3,t4,x,y;
	if(k==2){
		t1=a[0]*a[1];
		t2=fabs(a[0]-a[1])*2;
		x=gcd(t1,t2);
		printf("%I64d %I64d\n",t1/x,t2/x);
		return 0;
	}
	t1=a[0]*a[1];
	t2=fabs(a[0]-a[1])*2;
	for(i=1;i<k-1;i++){	
		t3=a[i]*a[i+1];
		t4=fabs(a[i]-a[i+1])*2;
		x=t1*t3;
		y=gcd(t1*t4,t2*t3);
		ll temp=gcd(x,y);
		t1=x/temp;
		t2=y/temp;
	}
	printf("%I64d %I64d\n",t1,t2);

	return 0;
}



