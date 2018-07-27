#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int H,R;
const double g=10.0;

double cal(int T)
{
	double h;
	if(T<=0)
		return h=H;
	int k,i;
	double t;
	t=sqrt(2*H/g);
	k=(int)T/t;
	if(k%2==0){
		double d=T-k*t;
		h=H-g*d*d/2;
	}
	else
	{
		double d=k*t+t-T;
		h=H-g*d*d/2;
	}
	return h;
}

int main()
{
	int C,n,i,T;
	double a[110];
	scanf("%d",&C);
	while(C--)
	{
		scanf("%d%d%d%d",&n,&H,&R,&T);
		
		for(i=0;i<n;i++)
		{
			a[i]=cal(T--);
		//	T--;
		}
		sort(a,a+n);
		if(R!=0)
			for(i=0;i<n;i++)
				a[i]+=((2*R*i)/100.0);
		for(i=0;i<n-1;i++)
			printf("%.2f ",a[i]);
		printf("%.2f\n",a[n-1]);
	}
	return 0;
}
		
