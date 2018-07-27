#include <stdio.h>
#include <queue>
using namespace std;
typedef __int64 ll;

ll bfs(int n){
	queue<ll> que;
	que.push(1);
	while(!que.empty()){
		ll t=que.front();
		que.pop();
		if(t%n==0)
			return t;
		que.push(t*10);
		que.push(t*10+1);
	}
}

int main()
{
	int i,n;
	while(scanf("%d",&n),n)
		printf("%I64d\n",bfs(n));
	return 0;
}