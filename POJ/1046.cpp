#include <stdio.h>
#include <string.h>
#include <math.h>
#define PI 3.1415926

double dis1(int sum)
{
	double r;
	r=sqrt((double)sum*2/PI);
	return r;
}

double dis2(double x,double y)
{
	return sqrt(x*x+y*y);
}

int main()
{
	int i,n,cas=1,z,sum;
	double x,y,l,k;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf%lf",&x,&y);
		l=dis2(x,y);
		z=1;
		for(sum=50;;sum+=50)
		{
			k=dis1(sum);
			if(k>=l)
				break;
			z++;
		}
		printf("Property %d: This property will begin eroding in year %d.\n",,cas++,z);
		
	}printf("END OF OUTPUT.\n");
	return 0;
}
