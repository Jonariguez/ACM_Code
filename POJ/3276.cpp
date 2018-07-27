#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef __int64 ll;

int dir[5005];	// 0 for F ,1 for B    All should be F finally.
int f[5005],n;

int cal(int k)
{
	memset(f,0,sizeof(f));
	int i,j,sum=0,res=0;
	for(i=0;i+k<=n;i++)		//�˳���i+k=n+1����i=n-k+1,������ʣ�µĺ����ţ�Ƿ񶼳�ǰ�ˣ�Ҫ�õĵ�
	{
		if((dir[i]+sum)%2){
			res++;
			f[i]=1;
		}
		sum+=f[i];
		if(i-k+1>=0)
			sum-=f[i-k+1];
	}
	//���ʣ�µ�ţ�Ƿ����泯���
	for(i=n-k+1;i<n;i++)
	{
		if((dir[i]+sum)%2){	//�泯�󣬷����޽�
			return -1;
		}
		if(i-k+1>=0)
			sum-=f[i-k+1];
	}
	return res;	//���ز�������
}

int main()
{
	int i,ans,t,k;
	char c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf(" %c",&c);
		if(c=='B')
			dir[i]=1;
		else
			dir[i]=0;
	}
	ans=100000;
	for(i=1;i<=n;i++)
	{
		t=cal(i);
		if(t>=0 && t<ans)
		{
			k=i;ans=t;
		}
	}
	printf("%d %d\n",k,ans);
	return 0;
}

