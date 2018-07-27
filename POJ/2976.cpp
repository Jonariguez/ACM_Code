#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
int a[maxn],b[maxn],n,k;
double t[maxn];

int cmp(double x,double y){
	return x>y;
}

bool C(double x){
	int cnt=0,i;
	double sum=0;
	for(i=0;i<n;i++)
		t[i]=a[i]-x*b[i];
	sort(t,t+n,cmp);
	for(i=0;i<n-k;i++)
		sum+=t[i];
	return sum>0;
}

int main()
{
	int i,j;
	while(scanf("%d%d",&n,&k)){
		if(n==0 && k==0) break;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		double l=0,r=1;
		for(i=0;i<20;i++){
			double m=(l+r)/2;
			if(C(m))
				l=m;
			else
				r=m;
		}
		printf("%d\n",(int)(l*100+0.5));
	}
	return 0;
}
		
