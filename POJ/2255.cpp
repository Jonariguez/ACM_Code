#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

char pre[30],mid[30],n;

typedef struct Node{
    char v;
    struct Node *left,*right;
}node;

node* root;

node* newNode(char x){
    node* u=(node*)malloc(sizeof(node));
    u->left=u->right=NULL;
    u->v=x;
    return u;
}

node* creat(char *pre,int l1,char *mid,int l2){
    int i,j,k;
    for(i=0;i<l2;i++)
        if(pre[0]==mid[i]) break;
    node* u=newNode(mid[i]);
    if(i>0)
        u->left=creat(pre+1,i,mid,i);
    if(i<l2-1)
        u->right=creat(pre+i+1,l2-i-1,mid+i+1,l2-i-1);
    return u;
}

void remove_tree(node* u){
    if(u==NULL) return ;
    remove_tree(u->left);
    remove_tree(u->right);
    delete u;
}

void print(node* u){
    if(u==NULL) return ;
    print(u->left);
    print(u->right);
    printf("%c",u->v);
}

int main()
{
    int i,j,n;
    while(scanf("%s",pre)!=EOF){
        scanf("%s",mid);
        n=strlen(pre);
        remove_tree(root);
        root=creat(pre,n,mid,n);
        print(root);
        printf("\n");
    }
    return 0;
}
