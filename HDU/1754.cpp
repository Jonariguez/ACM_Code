#include <stdio.h>
#include <string.h>
#include <math.h>
#define INF 10000000
#define MAX 200001
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)

int val[MAX*4];

void pushUp(int rt){
	val[rt]=max(val[rt*2],val[rt*2+1]);
}

void build(int L,int R,int rt){
	if(L==R){
		scanf("%d",&val[rt]);
		return ;
	}
	int m=(L+R)/2;
	build(L,m,rt*2);
	build(m+1,R,rt*2+1);
	pushUp(rt);
}

void update(int p,int v,int L,int R,int rt){
	if(L==R){
		val[rt]=v;
		return ;
	}
	int m=(L+R)/2;
	if(p<=m)
		update(p,v,L,m,rt*2);
	else
		update(p,v,m+1,R,rt*2+1);
	pushUp(rt);
}

int query(int a,int b,int L,int R,int rt){
	if(a<=L && b>=R)
		return val[rt];
	int res1=-1,res2=-1,m=(L+R)/2;
	if(a<=m)
		res1=query(a,b,L,m,rt*2);
	if(b>m)
		res2=query(a,b,m+1,R,rt*2+1);
	return max(res1,res2);
}

int main()
{
	int i,k,j,n,m,a,b;
	char s[10];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		build(1,n,1);
		while(m--){
			scanf("%s%d%d",s,&a,&b);
			if(s[0]=='Q')
				printf("%d\n",query(a,b,1,n,1));
			else
				update(a,b,1,n,1);
		}
	}
	return 0;
}
