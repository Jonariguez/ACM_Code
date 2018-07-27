#include <stdio.h>
#include <string.h>
#include <math.h>
typedef __int64 ll;

const int maxn=100000+10;

ll bit0[maxn],bit1[maxn];
int n,q;

void add(ll *b,ll i,ll v){
	while(i<=n){
		b[i]+=v;
		i+=i&(-i);
	}
}

ll sum(ll *b,ll i){
	ll res=0;
	while(i>0){
		res+=b[i];
		i-=i&(-i);
	}
	return res;
}

int main()
{
	int i,a,b,x;
	char op[3];
	while(scanf("%d%d",&n,&q)!=EOF){
		for(i=1;i<=n;i++){
			scanf("%d",&a);
			add(bit0,i,a);
		}
		while(q--){
			scanf("%s%d%d",op,&a,&b);
			if(op[0]=='C'){
				scanf("%d",&x);
				add(bit0,a,-(x*(a-1)));
				add(bit1,a,x);
				add(bit1,b+1,-x);
				add(bit0,b+1,x*b);
			}
			else {
				ll res=0;
				res+=sum(bit0,b)+sum(bit1,b)*b;
				res-=sum(bit0,a-1)+sum(bit1,a-1)*(a-1);
				printf("%I64d\n",res);
			}
		}
	}
	return 0;
}
