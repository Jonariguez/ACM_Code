#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef __int64 ll;

const int maxn=500000+10;
int bit[maxn],n;
int pos[maxn];

struct pp{
	int v,id;
}s[maxn];

int cmp(const pp &x,const pp &y){
	return x.v<y.v;
}

int lowbit(int x){
	return x&(-x);
}

void add(int i,int v){
	while(i<=n){
		bit[i]+=v;
		i+=lowbit(i);
	}
}

int cal(int i){
	int res=0;
	while(i>0){
		res+=bit[i];
		i-=lowbit(i);
	}
	return res;
}

int main()
{
	int i;
	ll res;
	while(scanf("%d",&n),n){
		res=0;
		memset(bit,0,sizeof(bit));
		for(i=1;i<=n;i++){
			scanf("%d",&s[i].v);
			s[i].id=i;
		}
		sort(s+1,s+n+1,cmp);
		for(i=1;i<=n;i++)
			pos[s[i].id]=i;
		for(i=n;i>=1;i--){			//要按从大到小的顺序放数到sum里
			res+=cal(pos[i]);
			add(pos[i],1);
		}
		printf("%I64d\n",res);
	}
	return 0;
}
