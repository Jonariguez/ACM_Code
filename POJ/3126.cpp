#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
#define HUR 100
#define THO 1000
#define TEN 10
const int maxn=10000;
bool prime[maxn+5];
int vis[maxn],s,e;

void prime_table(){
	int i,j;
	memset(prime,0,sizeof(prime));
	for(i=2;i<maxn;i++)
		if(!prime[i])
			for(j=i*i;j<maxn;j+=i)
				prime[j]=1;
}

int bfs(){
	int i;
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	queue<int> que;
	que.push(s);
	while(!que.empty()){
		int t=que.front();
		que.pop();
		int d=t;
		d%=1000;
		for(i=1;i<10;i++){
			int tt=d+i*THO;
			if(prime[tt]==0 && vis[tt]==0){
				if(tt==e) return vis[t];
				que.push(tt);vis[tt]=vis[t]+1;
			}
		}
		d=t%100+(t/1000*1000);
		for(i=0;i<10;i++){
			int tt=d+i*HUR;
			if(prime[tt]==0 && vis[tt]==0){
				if(tt==e) return vis[t];
				que.push(tt);vis[tt]=vis[t]+1;
			}
		}
		d=t%10+t/100*100;
		for(i=0;i<10;i++){
			int tt=d+i*TEN;
			if(prime[tt]==0 && vis[tt]==0){
				if(tt==e) return vis[t];
				que.push(tt);vis[tt]=vis[t]+1;
			}
		}
		d=t/10*10;
		for(i=0;i<10;i++){
			int tt=d+i;
			if(prime[tt]==0 && vis[tt]==0){
				if(tt==e) return vis[t];
				que.push(tt);vis[tt]=vis[t]+1;
			}
		}
	}
	return 0;
}

int main()
{
	int T,res;
	prime_table();
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&s,&e);
		if(s==e){
			printf("0\n");
			continue;
		}
		res=bfs();
		if(res==0)
			printf("Impossible\n");
		else
			printf("%d\n",res);
	}
	return 0;
}






