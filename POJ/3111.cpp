/*
01分数规划+记录选择
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define eps 1e-10

const int maxn=100000+10;
int k,n;

struct pp
{
	double c;
	int v,w;	//v，w一定要和id同在一个结构体里，不然会WA死
	int id;
}s[maxn];

int cmp(const pp &x,const pp &y){
	return x.c>y.c;
}

int cmp1(const pp &x,const pp &y){
	return x.id<y.id;
}

bool C(double x){
	int i;
	double sum=0;
	for(i=0;i<n;i++){
		s[i].c=s[i].v-s[i].w*x;
	}
	sort(s,s+n,cmp);
	for(i=0;i<k;i++)
		sum+=s[i].c;
	if(sum<0) return false;
	return true;
}

int main()
{
	int i;
	while(scanf("%d%d",&n,&k)!=EOF){
		for(i=0;i<n;i++){
			scanf("%d%d",&s[i].v,&s[i].w);
			s[i].id=i+1;
		}
		double l=0,r=10000000;
		for(i=0;i<50;i++){
			double m=(l+r)/2;
			if(C(m))
				l=m;
			else
				r=m;
		}
		sort(s,s+k,cmp1);
		for(i=0;i<k;i++)
			printf("%d%c",s[i].id,i==k-1?'\n':' ');
	}
	return 0;
}