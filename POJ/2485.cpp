#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int v[550][550];

struct pp
{
	int a,b,l;
}s[250000];

int f[550];

void init(){
	int i;
	for(i=0;i<550;i++) f[i]=i;
}

int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}

bool Union(int u,int v){
	if((v=find(v))==(u=find(u))) return false;
	f[v]=u;
	return true;
}

int cmp(const pp &x,const pp &y){
	return x.l<y.l;
}

int main()
{
	int i,j,k,t,T,n,cnt;
	__int64 res;
	while(scanf("%d",&n)!=EOF){	
		init();
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&v[i][j]);
		k=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=i;j++)
			if(i!=j){
				s[k].a=i;s[k].b=j;
				s[k++].l=v[i][j];
			}
		res=cnt=0;
		sort(s,s+k,cmp);
		for(i=0;i<k;i++){
			if(Union(s[i].a,s[i].b)){
				res+=s[i].l;
				if(++cnt==n-1)
					break;
			}
		}
		printf("%I64d\n",res);
	}
	return 0;
}



