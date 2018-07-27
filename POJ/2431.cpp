#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int a[1010],b[1010];

int main()
{
	int l,p,n,i,j,t,rank,pos;
	int res;
//	priority_queue<int,vector<int>,less<int> > q;
	priority_queue<int> q;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&a[i],&b[i]);
	scanf("%d%d",&l,&p);
	a[n]=l;b[n]=0;
	res=0;t=0;rank=p;pos=0;
	for(i=0;i<=n;i++)
	{
		t=a[i]-pos;
		while(rank<t)
		{
			if(q.empty()){
				puts("-1");
				return 0;
			}
			rank+=q.top();
			q.pop();
			res++;
		}
		rank-=t;
		pos=a[i];
		
		q.push(b[i]);
	//	res++;
	}
	printf("%d\n",res);




	return  0;
}

