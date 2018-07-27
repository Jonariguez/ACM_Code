#include <stdio.h>
#include <string.h>
#include <math.h>
typedef __int64 ll;

int main()
{
	int i,j,a[6]={0,2,4,7,9,12};
	ll s,d,res;
	while(scanf("%I64d%I64d",&s,&d)!=EOF)
	{
		for(i=4;i>0;i--)
			if(s*i-d*(5-i)<0)
				break;
		if(i==0)
		{
			printf("Deficit\n");
			continue;
		}
		i=5-i;
		res=s*(12-a[i])-d*a[i];
		if(res<0)
			printf("Deficit\n");
		else
			printf("%I64d\n",res);
	}
	return 0;
}



