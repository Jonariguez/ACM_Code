#include <stdio.h>
#include <string.h>
#define MAX 100005


int sum[MAX*4],set[MAX*4];

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}

void pushUp(int k,int l,int r){
	sum[k]=sum[k*2]+sum[k*2+1];
}

void pushDown(int k,int l,int r){
	if(set[k]){
		set[k*2]=set[k*2+1]=set[k];
		int m=(l+r)/2;
		sum[k*2]=(m-l+1)*set[k];		//向下更新维护左右还孩子的sum
		sum[k*2+1]=(r-m)*set[k];
		set[k]=0;
	}
}

void build(int k,int l,int r){
	set[k]=0;
	sum[k]=1;		//初始为1，可改成scanf作为输入
	if(l==r)return;
	int m=(l+r)/2;
	build(k*2,l,m);
	build(k*2+1,m+1,r);
	pushUp(k,l,r);
}


void update(int a,int b,int v,int k,int l,int r){
	if(a<=l && r<=b){
		set[k]=v;
		sum[k]=v*(r-l+1);
	}
	else {
		pushDown(k,l,r);
		int m=(l+r)/2;
		if(a<=m)
			update(a,b,v,k*2,l,m);
		if(b>m)
			update(a,b,v,k*2+1,m+1,r);	
		pushUp(k,l,r);
	}

}

int res;

void query(int a,int b,int k,int l,int r){
	if(set[k]>0){
		res+=set[k]*(min(b,r)-max(a,l)+1);
	}
	else if(a<=l && r<=b){
		res+=sum[k];
	}
	else {
		int m=(l+r)/2;
		if(a<=m)
			query(a,b,k*2,l,m);
		if(b>m)
			query(a,b,k*2+1,m+1,r);
	}
}

int main()
{
	int i,n,q,x,y,z,cas=1;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		build(1,1,n);
		while(q--)
		{
			scanf("%d%d%d",&x,&y,&z);
			update(x,y,z,1,1,n);
		}
		res=0;
	//	query(1,n,1,1,n);
		printf("Case %d: The total value of the hook is %d.\n",cas++,sum[1]);
	}
	return 0;
}

