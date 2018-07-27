#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn=266;

typedef struct Node{
	int cnt;
	struct Node *ch[maxn];
}node;

node *T;
int tot;

void insert(char s[]){
	int i,j,len=strlen(s);
	node *u;
	u=T;
	for(i=0;i<len;i++){
		int id=s[i];
		if(u->ch[id]==0){
			node *t=(node*)malloc(sizeof(node));
			for(j=0;j<maxn;j++) t->ch[j]=0;
			t->cnt=0;
			u->ch[id]=t;
		}
		u=u->ch[id];
	}
	u->cnt++;
}

char name[40];
	
void ask(node* T,int cur){
	if(T==0) return ;
	int i;
	double res;
	if(T->cnt) {
		name[cur]='\0';
		res=(double)T->cnt/tot*100;
		printf("%s %.4f\n",name,res);
	}
	for(i=0;i<maxn;i++)
		if(T->ch[i]!=0){
			name[cur]=i;
			ask(T->ch[i],cur+1);
		}
	return ;
}

int main()
{
	int i,res,len;
	char str[40];
	T=(node*)malloc(sizeof(node));
	for(i=0;i<maxn;i++) T->ch[i]=0;
	T->cnt=0;
	tot=0;
	while(gets(str)){
		if(str[0]=='\0') break;
		insert(str);
		tot++;
	}
	ask(T,0);
	return 0;
}
