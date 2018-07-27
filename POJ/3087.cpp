#include <stdio.h>
#include <string.h>

const int maxn=105;
char result[2*maxn],s[2*maxn];
char or1[maxn],or2[maxn];

int main()
{
	int i,k,T,kcase=1,c,res;
	char s1[110],s2[110];
	scanf("%d",&T);
	while(T--){
		scanf("%d",&c);
		scanf("%s%s%s",s1,s2,result);
		strcpy(or1,s1);
		strcpy(or2,s2);
		int index1,index2;		
		res=0;
		do{
			index1=index2=0;
			for(i=0;i<c*2;i++){
				if(i&1)
					s[i]=s1[index1++];
				else 
					s[i]=s2[index2++];
			}
			s[c*2]='\0';
			for(i=0;i<c;i++)
				s1[i]=s[i];
			for(;i<c*2;i++)
				s2[i-c]=s[i];
			res++;
			if(strcmp(s1,or1)==0 && strcmp(s2,or2)==0){
				res=-1;break;
			} 
			if(strcmp(s,result)==0) break;			
		}while(1);
		printf("%d %d\n",kcase++,res);
	}
	return 0;
}

