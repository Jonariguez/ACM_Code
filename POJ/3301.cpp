#include <stdio.h>
#include <string.h>
#include <math.h>

__int64 cal(__int64 n){
	if(n<0) return 0;
	if(n==0) return 1;
	__int64 res=1,w=10;
	while(n){
		if(n<w) break;
		res+=(n/w-1)*(w/10);	//前面[1,n/w-1]一共n/w-1种情况，程序后面一共是w/10种情况
		if(n%w/(w/10)>0)		//考虑前面等于n/w的情况，如果n的当前位不为0，后面还有w/10种情况，否则应该是不超过n的后几位n%w，[0,n%w]共n%w种
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

