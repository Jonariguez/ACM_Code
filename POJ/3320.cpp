#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define min(a,b) (a)<(b)?(a):(b)

int a[1000003];	

int main()
{
	int i,j,k,n,num,sum,s,t;
	int res;
	map<int,int> p;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	set<int> all;
	for(i=0;i<n;i++)
		all.insert(a[i]);
	sum=all.size();
	t=0;num=0;res=n;
	for(s=0;s<n;s++)
	{
		while(t<n && num<sum)
		{
			if(p[a[t]]==0)
				num++;
			p[a[t++]]++;
		}
		if(num==sum)
		{
			res=min(res,t-s);
			if(--p[a[s]]==0)
				num--;	
		}
		else
			break;
	}
	printf("%d\n",res);
	return 0;
}
