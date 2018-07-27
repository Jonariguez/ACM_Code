#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
	int i,j,k,t,sum,n,r,a[1010],res;
	while(scanf("%d%d",&r,&n))
	{
		if(r==-1 && n==-1)
			break;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		sum=0;res=0;
		for(i=0;i<n;)
		{
			t=a[i];
			while(i<n && a[i]-t<=r)
				i++;
			t=a[i-1];
			while(i<n && a[i]-t<=r)
				i++;
			res++;

		}
		printf("%d\n",res);
	}
	return 0;
}