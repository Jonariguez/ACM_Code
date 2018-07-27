/*
线段树（多数组维护）
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef __int64 ll;

const int maxn=100000+10;
const int maxdata=(1<<18)-1;

int n,q;

int max(int x,int y){
	if(x>y) return x;
	return y;
}

int min(int x,int y){
	if(x<y) return x;
	return y;
}

ll data[maxdata],datb[maxdata];

void add(int a,int b,int v,int k,int l,int r){
	if(a<=l && r<=b){
		data[k]+=v;
		return ;
	}
	if(l<=b && a<=r){
		datb[k]+=(min(b,r)-max(a,l)+1)*v;
		int m=(l+r)/2;
		add(a,b,v,k*2,l,m);
		add(a,b,v,k*2+1,m+1,r);
	}
}

ll sum(int a,int b,int k,int l,int r){
	if(b<l || a>r)
		return 0;
	if(a<=l && r<=b){
		return data[k]*(r-l+1)+datb[k];
	}
	ll res=(min(b,r)-max(a,l)+1)*data[k];
	res+=sum(a,b,k*2,l,(l+r)/2);
	res+=sum(a,b,k*2+1,(l+r)/2+1,r);
	return res;
}

int main()
{
	int i,a,b,c;
	char op[3];
	while(scanf("%d%d",&n,&q)!=EOF){
		for(i=1;i<=n;i++){
			scanf("%d",&a);
			add(i,i,a,1,1,n);
		}
		while(q--){
			scanf("%s%d%d",op,&a,&b);
			if(op[0]=='C'){
				scanf("%d",&c);
				add(a,b,c,1,1,n);
			}
			else
				printf("%I64d\n",sum(a,b,1,1,n));
		}
	}
	return 0;
}

