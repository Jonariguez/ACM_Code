#include <stdio.h>
#include <string.h>
#include <math.h>
#define min(a,b) (a<b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define lc k*2
#define rc k*2+1
typedef __int64 ll;
const int MAX=200005;

int sum[MAX*4];

int max(int a,int b){
	return a>b?a:b;
}

void pushUp(int k){
	sum[k]=max(sum[k*2],sum[k*2+1]);
}

void update(int p,int v,int k,int l,int r){
	if(l==r){
		sum[k]=v;
		return ;
	}
	int m=(l+r)/2;
	if(p<=m)
		update(p,v,lson);
	else
		update(p,v,rson);
	pushUp(k);
}

int query(int a,int b,int k,int l,int r){
	if(a<=l && r<=b){
		return sum[k];
	}
	int m=(l+r)/2,res=-1;
	if(a<=m)
		res=max(res,query(a,b,lson));
	if(b>m)
		res=max(res,query(a,b,rson));
	return res;
}

int main()
{
	int i,n,x,a,b,T,cas=1,q;
	char s[10];
	int  res;
	while(scanf("%d%d",&n,&q)!=EOF){		
		memset(sum,0,sizeof(sum));
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			update(i,x,1,1,n);
		}
		while(q--){
			scanf("%s%d%d",s,&a,&b);
			if(s[0]=='U'){
				update(a,b,1,1,n);
			}
			else {
				printf("%d\n",query(a,b,1,1,n));
			}
		}
	}
	return 0;
}




