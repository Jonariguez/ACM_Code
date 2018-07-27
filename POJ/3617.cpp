#include <stdio.h>
#include <string.h>

char s[2020];

int judge(int l,int r)
{
	while(l!=r)
	{
		if(s[l]==s[r])
			l++,r--;
		else if(s[l]<s[r])
			return 1;
		else
			return 0;
	}
	return 1;
}

int main()
{
	int i,j,n,k,cnt;
	int lift,right;

	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf(" %c",&s[i]);
	s[n]='\0';
	lift=0;right=n-1;cnt=0;
	while(lift!=right)
	{
		if(s[lift]<s[right])
			printf("%c",s[lift++]);
		else if(s[lift]>s[right])
			printf("%c",s[right--]);
		else 
		{
			if(judge(lift,right))
				printf("%c",s[lift++]);
			else
				printf("%c",s[right--]);
		}
		cnt++;
		if(cnt%80==0)
			printf("\n");
	}
	printf("%c\n",s[lift]);
	return 0;
}


