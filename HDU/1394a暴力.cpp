#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,k,n,res,cnt,a[5005];
	int c[5005],sum;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);	
		cnt=0;
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
				if(a[j]<a[i])
					cnt++;
		}
		res=cnt;
		for(i=0;i<n;i++)
		{
			cnt=(cnt-a[i]+n-a[i]-1);
			if(res>cnt)
				res=cnt;
		}
		printf("%d\n",res);
	}
	return 0;
}
