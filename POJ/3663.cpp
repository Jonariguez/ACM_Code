/*
Trie(字典树)
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef __int64 ll;

typedef struct Node{
	char word[15];
	struct Node *ch[27];	//没想到ch[]的初值可以为0，一开始我用NULL异常退出了
}node;

node *T;
int index;

void add(char s[],char wd[]){
	node *u;
	u=T;
	int len=strlen(s),i;

	for(i=0;i<len;i++){
		if(u->ch[s[i]-'a']==0){
			node *t=(node*)malloc(sizeof(node));
			for(int j=0;j<27;j++)
				t->ch[j]=0;
			u->ch[s[i]-'a']=t;
		}
		u=u->ch[s[i]-'a'];
	}
	strcpy(u->word,wd);
}

void ask(char s[]){
	node* u=T;
	int i,len=strlen(s);
	for(i=0;i<len;i++){
		if(u==0){
			printf("eh\n");
			return ;
		}
		else 
			u=u->ch[s[i]-'a'];
	}
	printf("%s\n",u->word);
}


int main()
{
	int i,k,j;
	char s1[20],s2[20],str[50];
	T=(node*)malloc(sizeof(node));
	for(i=0;i<27;i++)
		T->ch[i]=0;
	while(gets(str)){
		if(str[0]=='\0') break;
		sscanf(str,"%s %s",s1,s2);		//需要借助sscanf来处理
		add(s2,s1);
	}
	while(scanf("%s",s1)!=EOF){
		ask(s1);
	}
	return 0;
}

