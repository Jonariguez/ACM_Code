/*
���������� 
*/
#include <stdio.h>
#include <string.h>

const int maxn=100000+10;
int n,m;
int a[maxn];

bool C(int x){
	int i,cnt=1,sum=0;
	for(i=0;i<n;i++){
		if(a[i]>x) return false;
		sum+=a[i];
		if(sum>x){	//���>x�ˣ�����¾Ϳ���ͣ������i��һ��Ҫ�㵽�¸�����
			sum=a[i];
			cnt++;
		}
	}
	return cnt<=m;
}


int main()
{
	int i,max;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		int l=-1,r=1000000000;
		while(r-l>1){
			int M=(l+r)/2;
			if(C(M))
				r=M;
			else
				l=M;
		}		
		printf("%d\n",r);
	}
	return 0;
}