#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 50005

int sum[MAX*4];		//必须*4   *2的话是Runtime Error—(ACCESS_VIOLATION)

void pushUp(int rt){
	sum[rt]=sum[rt*2]+sum[rt*2+1];
}

void build(int l,int r,int rt){
	if(l==r){
		scanf("%d",&sum[rt]);
		return ;
	}
	int m=(l+r)/2;
	build(l,m,rt*2);
	build(m+1,r,rt*2+1);
	pushUp(rt);
}

void update(int p,int add,int l,int r,int rt){
	if(l==r){
		sum[rt]+=add;
		return ;
	}
	int m=(l+r)/2;
	if(p<=m)	update(p,add,l,m,rt*2);
	else	update(p,add,m+1,r,rt*2+1);
//	sum[rt]=sum[rt*2]+sum[rt*2+1];		也行
	pushUp(rt);
}

int query(int a,int b,int l,int r,int rt){
	if(a<=l && b>=r)
		return sum[rt];
	int m=(l+r)/2,res1=0,res2=0;
	if(a<=m) res1=query(a,b,l,m,rt*2);
	if(b>m) res2=query(a,b,m+1,r,rt*2+1);
	return res1+res2;
}

int main()
{
	int i,T,n,a,b,cas=1;
	char s[10];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("Case %d:\n",cas++);
		build(1,n,1);
		while(scanf("%s",s)){
			if(s[0]=='E')
				break;
			scanf("%d%d",&a,&b);
			if(s[0]=='Q')
				printf("%d\n",query(a,b,1,n,1));
			else if(s[0]=='A')
				update(a,b,1,n,1);
			else if(s[0]=='S')
				update(a,-b,1,n,1);
		}
	}
	return 0;
}