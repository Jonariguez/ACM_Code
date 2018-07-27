#include <stdio.h>
#include <string.h>
#define MAX 100002
typedef __int64 ll;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

ll data[MAX*4],datb[MAX*4];

void update(ll a,ll b,ll x,ll l,ll r,ll rt){
//	printf("l=%I64d,r=%I64d\n",l,r);
	if(a<=l && b>=r){
		data[rt]+=x;
		return ;
	}
	else if(a<l && b>=l || b>r && a<=r || a>=l && b<=r){
		datb[rt]+=(min(b,r)-max(a,l)+1)*x;
		ll m=(l+r)/2;
		update(a,b,x,l,m,rt*2);
		update(a,b,x,m+1,r,rt*2+1);
	}
}

ll query(ll a,ll b,ll l,ll r,ll rt){
	if(a>r || b<l)
		return 0;
	if(a<=l && b>=r){
		return datb[rt]+data[rt]*(r-l+1);
	}
	else {
		ll res=(min(b,r)-max(a,l)+1)*data[rt];
		ll m=(l+r)/2;
		res+=query(a,b,l,m,rt*2);
		res+=query(a,b,m+1,r,rt*2+1);
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
	for(i=1;i<=n;i++)
	{
		scanf("%I64d",&t);
		update(i,i,t,1,n,1);
	}
	for(i=1;i<=n;i++)
		printf("data[%I64d]=%I64d,datb[%I64d]=%I64d\n",i,data[i],i,datb[i]);
	while(q--)
	{
		scanf("%s%I64d%I64d",s,&a,&b);
		if(s[0]=='C')
		{
			scanf("%I64d",&x);
			update(a,b,x,1,n,1);
		}
		else {
			printf("%I64d\n",query(a,b,1,n,1));
		}
	}
	return 0;
}

