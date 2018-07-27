#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef __int64 ll;
#define MAX 20000

typedef struct PQueue
{
	ll Num[MAX+2],Tot;
	PQueue() { Tot=0; }
	ll size() { return Tot; }
	ll top() { return Num[1]; }
	void push(ll x){
		Num[++Tot]=x;
		ll s=Tot,p=s/2;
		while(p>=1)
		{
			if(Num[p]<=x)
				break;
			Num[s]=Num[p];
			s=p;p/=2;
		}
		Num[s]=x;
	}
	void pop(){
		Num[1]=Num[Tot--];
		ll p=1,a,x=Num[1];
		while(p*2<=Tot)
		{
			a=p*2;
			if(a<Tot && Num[a]>Num[a+1])
				a++;
			if(Num[a]>=x)
				break;
			Num[p]=Num[a];
			p=a;
		}
		Num[p]=x;
	}
}PQueue;

int main()
{
	ll i,k,n,t1,t2,res;
	while(scanf("%I64d",&n)!=EOF)
	{
		PQueue Q;
		for(i=0;i<n;i++)
		{
			scanf("%I64d",&k);
			Q.push(k);
		}
		res=0;
		while(Q.size()!=1)
		{
			t1=Q.top();Q.pop();
			t2=Q.top();Q.pop();
			res+=(t1+t2);
			Q.push(t1+t2);
		}
		printf("%I64d\n",res);
	}
	return 0;
}


