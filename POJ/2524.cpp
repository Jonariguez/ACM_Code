#include <stdio.h>  
#include <math.h>   

int vis[100010];	//0->(   1->)

int main()  
{
	int i,j,T,n,s[22],w[22];
	int a,b,right,k,v;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&s[i]);
		j=1;right=0;i=1;
			for(j=1;i<=n && j<=s[i]+right+1;j++)
			{
				if(j==s[i]+right+1)
				{
					vis[j]=1;
					right++;
					k=j;a=0;b=0;
					while(k>0)
					{
						if(vis[k])
							b++;
						else a++;
						if(a==b)
							break;
						k--;
					}
					w[i]=a;
					i++;
				}
				else
					vis[j]=0;
			}
		for(i=1;i<n;i++)
			printf("%d ",w[i]);
		printf("%d\n",w[i]);
	}
	return 0;
}