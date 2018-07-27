#include <stdio.h>
#include <string.h>

char s[100005];
int f[100005];
int res[100005];

int main()
{
	int i,j,k,sum,len,l_sum,r_sum,c_sum;
	while(scanf("%s",s)!=EOF)
	{
		len=strlen(s);
		l_sum=r_sum=c_sum=k=0;
		for(i=0;i<len;i++)
		{
			if(s[i]=='(')
				l_sum++;
			else if(s[i]==')')
				r_sum++;
			else
				f[c_sum++]=l_sum-r_sum;
		}
		if(r_sum>l_sum || r_sum+c_sum>l_sum)
		{
			printf("-1\n");
			continue;
		}
		sum=c_sum;
		for(i=0;i<sum;i++)
		{
			if(c_sum>f[i])
			{
				res[i]=f[i]+1;
				c_sum-=(f[i]+1);
			}
			else
				break;
		}
		if(i==sum)
		{
			for(i=0;i<sum;i++)
				printf("%d\n",res[i]);
		}
		else
			printf("-1\n");
	}
	return 0;
}


