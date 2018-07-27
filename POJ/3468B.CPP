#include <stdio.h>
#include <string.h>
#define MAX 100002
typedef __int64 ll;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

ll data[MAX*4],datb[MAX*4];

void update(ll a,ll b,ll x,ll k,ll l,ll r){
//	printf("l=%I64d,r=%I64d\n",l,r);
	if(a<=l && r<=b){
		data[k]+=x;
	}
	else if(l<b && a<r){
		datb[k]+=(min(b,r)-max(a,l))*x;
		ll m=(l+r)/2;
		update(a,b,x,k*2+1,l,m);
		update(a,b,x,k*2+2,m,r);
	}
}

ll query(ll a,ll b,ll k,ll l,ll r){
	if(b<=l || r<=a)
		return 0;
	else if(a<=l && r<=b){
		return data[k]*(r-l)+datb[k];
	}
	else {
		ll res=(min(b,r)-max(a,l))*data[k];
		ll m=(l+r)/2;
		res+=query(a,b,k*2+1,l,m);
		res+=query(a,b,k*2+2,m,r);
		return res;
	}
}

int main()
{
	ll i,l,a,b,x,n,q,t;
	char s[5];
	memset(data,0,sizeof(data));
	memset(datb,0,sizeof(datb));

	scanf("%I64d%I64d",&n,&q);	
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&t);
		update(i,i+1,t,0,0,n);
	}
//	for(i=0;i<n;i++)
//		printf("data[%I64d]=%I64d,datb[%I64d]=%I64d\n",i,data[i],i,datb[i]);
	while(q--)
	{
		scanf("%s%I64d%I64d",s,&a,&b);
		if(s[0]=='C')
		{
			scanf("%I64d",&x);
			update(a,b+1,x,0,0,n);
		}
		else {
			printf("%I64d\n",query(a,b+1,0,0,n));
		}
	}
	return 0;
}

