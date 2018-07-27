#include <stdio.h>
#include <string.h>
#include <math.h>
typedef __int64 ll;

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

ll cal(char *s,ll len){
	ll i,res=0;
	for(i=0;i<len;i++)
		res=res*10+(s[i]-'0');
	return res;
}

ll _pow(ll a,ll b){
	ll res=1,i;
	for(i=0;i<b;i++)
		res*=a;
	return res;
}

int main()
{
	ll i,len;
	char str[100];
	while(scanf("%s",str) && strcmp(str,"0")){
		ll pos,len2;
		len=strlen(str);
		for(pos=2;pos<len;pos++)
			if(str[pos]=='.')
				break;
		pos--;
		len2=pos-1;		//小数点后面长度为len2
		ll all=cal(str+2,pos-1);
		if(all==0){
			printf("0/1\n");
			continue;
		}
		ll minx,miny=100000000000,g,num,lens,x,y;
		minx=miny;					//初始化要足够大
		for(i=0;i<len2;i++){		//注意num可以为0
			num=cal(str+2,i);	//从第一位小数开始，分别求1位，2位，3位。。。的情况
			lens=len2-i;
			x=all-num;
			y=_pow(10,i)*(_pow(10,len2-i)-1);
			g=gcd(x,y);
			x/=g;
			y/=g;
			if(miny>y){
				miny=y;
				minx=x;
			}
		}/*
		num=all;ll k=1;
		for(i=1;i<=len2;i++){
			num/=10;
			k*=10;
			ll a=all-num;
			ll b=_pow(10,len2-i)*(k-1);
			g=gcd(a,b);
			a/=g;
			b/=g;
			if(b<miny){
				miny=b;minx=a;
			}
		}*/
		printf("%I64d/%I64d\n",minx,miny);
	}
	return 0;
}


