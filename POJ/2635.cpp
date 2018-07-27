#include <stdio.h>
#include <string.h>
typedef __int64 ll;
const int maxl=1000000;
bool is[maxl+2];
int p[200000],tot;

void prime_table(){
	int i,j;
	tot=0;
	memset(is,0,sizeof(is));
	for(i=2;i*i<=maxl;i++)
		if(!is[i]){
			p[tot++]=i;
			for(j=i*i;j<=maxl;j+=i)
				is[j]=1;
		}
}

char K[110];
ll k,l;

int main()
{
	int i,len,j;
	prime_table();
	while(scanf("%s%I64d",K,&l)){
		if((len=strlen(K))==1 && K[0]=='0' && l==0) break;
		if(len<=18){
			k=0;
			for(i=0;i<len;i++)
				k=k*10+(K[i]-'0');
		}
		else {
			if(K[len-18]=='0')k=1;
			else k=0;
			for(i=len-18;i<len;i++)
				k=k*10+(K[i]-'0');
		}
		int ok=0;
		for(i=0;i<tot;i++){
			if(p[i]>l){
				ok=1;break;
			}
			if(k%p[i]==0) break;
		}
		if(ok)
			puts("GOOD");
		else
			printf("BAD %d\n",p[i]);
	}
	return 0;
}