#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct student 
{
	int age;
	double score;
	char name[100];
};

int main()
{
	int i,j;
	int len;
	scanf("%d",&len);
	struct student * pst;
	int t;
	pst = (struct student *)malloc(len * sizeof(struct student));

	for(i=0;i<len;++i)
	{
		scanf("%d",&pst[i].age);
		scanf("%lf",&pst[i].score);
		scanf("%s",pst[i].name);
	}

	for(i=0;i<len-1;++i)
	{
		for(j=0;j<len-1-i;++j)
		{
			if(pst[j].age > pst[j+1].age)
			{
				t=(*pst)[j].age;
				(*pst)[j].age=(*pst)[j+1].age;
				(*pst)[j+1].age=t;
			}
		}
	}		

	for(i=0;i<len;++i)
	{
		printf("%d  ",pst[i].age);
		printf("%.1lf  ",pst[i].score);
		printf("%s\n",pst[i].name);
	}	

	return 0;
}