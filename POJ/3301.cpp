#include <stdio.h>
#include <string.h>
#include <math.h>

__int64 cal(__int64 n){
	if(n<0) return 0;
	if(n==0) return 1;
	__int64 res=1,w=10;
	while(n){
		if(n<w) break;
		res+=(n/w-1)*(w/10);	//ǰ��[1,n/w-1]һ��n/w-1��������������һ����w/10�����
		if(n%w/(w/10)>0)		//����ǰ�����n/w����������n�ĵ�ǰλ��Ϊ0�����滹��w/10�����������Ӧ���ǲ�����n�ĺ�λn%w��[0,n%w]��n%w��
			res+=w/10;
		else
			res+=(n%w+1);		
		w*=10;
	}
	return res;
}

int main()
{
	__int64 n,m;
	while(scanf("%I64d%I64d",&m,&n)){
		if(n==-1 && m==-1) break;
		printf("%I64d\n",cal(n)-cal(m-1));
	}
	return 0;
}

