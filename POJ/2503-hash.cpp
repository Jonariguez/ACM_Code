#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define M 100003

const int maxn=100000+10;
char tag[maxn][12];
char str[50];

typedef struct Node{
    int Hash;
    char S[20];
    struct Node *next;
}node;

node* link[M];

node* newNode(int n){
    node* u=(node*)malloc(sizeof(node));
    u->Hash=n;
    return u;
}

int ELFhash(char *key){
    unsigned long h=0,g;
    while(*key){
        h=(h<<4)+*key++;
        g=h & 0xf0000000L;
        if(g)
            h^=g>>24;
        h&=~g;
    }
    return h%M;
}

int main()
{
    int i,j,n=0;
    char s1[20],s2[20];
    while(gets(str)){
        if(str[0]=='\0') break;
        sscanf(str,"%s %s",s1,s2);
        strcpy(tag[n],s1);
        int e=ELFhash(s2);
        if(!link[e]){
            link[e]=(node*)malloc(sizeof(node));
            link[e]->next=NULL;
        }
        node* p=newNode(n);
        p->next=link[e]->next;
        link[e]->next=p;
        strcpy(p->S,s2);
        n++;
    }
    while(scanf("%s",str)!=EOF){
        int e=ELFhash(str);
        node* p=link[e];
        while(p){
            if(strcmp(p->S,str)==0) break;
            p=p->next;
        }
        if(p)
            printf("%s\n",tag[p->Hash]);
        else
            printf("eh\n");
    }
    return 0;
}
