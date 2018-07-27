#include <stdio.h>
#include <string.h>
#include <math.h>

const int maxn=30000;

typedef struct UFSet{
	int par[maxn+5],rank[maxn+5];
	void init(int n){
		int i;
		for(i=0;i<n;i++) par[i]=i;
		for(i=0;i<n;i++) rank[i]=1;
	}
	int find(int u){ return u==par[u]?u:par[u]=find(par[u]);}
	void Union(int u,int v){
		if((u=find(u))==(v=find(v))) return ;
		if(rank[u]<=rank[v]){
			par[u]=v;rank[v]+=rank[u];
		}
		else {
			par[v]=u;rank[u]+=rank[v];
		}
	}
}UFS;

int main()
{
	int i,j,k,n,m,a,b;
	while(scanf("%d%d",&n,&m)){
		if(n==0 && m==0) break;
		UFS s;
		s.init(n);
		for(i=0;i<m;i++){
			scanf("%d",&k);
			if(k==0) continue;
			scanf("%d",&a);
			k--;
			while(k--){
				scanf("%d",&b);
				s.Union(a,b);
			}
		}
		k=s.find(0);		//这里是find(0) 而非par[0]
		printf("%d\n",s.rank[k]);
	}
	return 0;
}

