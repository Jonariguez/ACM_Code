#include <stdio.h>
#include <string.h>
#define MAX 5005


int sum[MAX*4];

int min(int a,int b)
{
	return a<b?a:b;
}

void pushUp(int rt){
	sum[rt]=sum[rt*2]+sum[rt*2+1];
}

void update(int p,int L,int R,int rt){
	if(L==R){
		sum[rt]++;
		return ;
	}
	int m=(L+R)/2;
	if(p<=m)
		update(p,L,m,rt*2);
	else
		update(p,m+1,R,rt*2+1);
	pushUp(rt);
}

int query(int a,int b,int L,int R,int rt){
	if(a<=L && b>=R)
		return sum[rt];
	int m=(L+R)/2,res=0;
	if(a<=m)
		res+=query(a,b,L,m,rt*2);
	if(b>m)
		res+=query(a,b,m+1,R,rt*2+1);
	return res;
}

int main()
{
	int i,j,k,n,a[5005],cnt;
	int res;
	while(scanf("%d",&n)!=EOF)
	{
		memset(sum,0,sizeof(sum));
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		cnt=0;
		for(i=0;i<n;i++)
		{
			cnt+=query(a[i],n-1,0,n-1,1);
			update(a[i],0,n-1,1);
		}
		res=cnt;
		for(i=0;i<n;i++)
		{
			cnt=(cnt-a[i]+n-a[i]-1);
			res=min(res,cnt);
		}
		printf("%d\n",res);
	}
	return 0;
}
