#include <stdio.h>
#include <string.h>
typedef __int64 ll;

const int MAX=(1<<18)-1;

int n,q;
ll sum[MAX],add[MAX];

int max(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}

int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}

void maintain(int k,int l,int r){
	int lc=k*2,rc=k*2+1;
	sum[k]=0;
	if(r>l)
		sum[k]=sum[lc]+sum[rc];
	sum[k]+=add[k]*(r-l+1);
}

void update(int a,int b,int v,int k,int l,int r){
	int lc=k*2,rc=k*2+1;
	if(a<=l && r<=b)
		add[k]+=v;
	else {
		int m=(l+r)/2;
		if(a<=m)
			update(a,b,v,lc,l,m);
		if(b>m)
			update(a,b,v,rc,m+1,r);
	}
	maintain(k,l,r);
}

ll res;

void query(int a,int b,int k,int l,int r,ll addv){
	if(a<=l && r<=b){
		res+=sum[k]+addv*(r-l+1);
	}
	else {
		int m=(l+r)/2;
		if(a<=m)
			query(a,b,k*2,l,m,addv+add[k]);
		if(b>m)
			query(a,b,k*2+1,m+1,r,addv+add[k]);
	}
}

int main()
{
	int i,a,b,x,t;
	char s[3];
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		update(i,i,t,1,1,n);
	}
	while(q--)
	{
		scanf("%s",s);
		if(s[0]=='C'){
			scanf("%d%d%d",&a,&b,&x);
			update(a,b,x,1,1,n);
		}
		else {
			scanf("%d%d",&a,&b);
			res=0;
			query(a,b,1,1,n,0);
			printf("%I64d\n",res);
		}
	}
	return 0;
}

