#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int pre[1100],mid[1100],n;

typedef struct Node{
    int v;
    struct Node *left,*right;
}node;

node* root;

node* newNode(int x){
    node* u=(node*)malloc(sizeof(node));
    u->left=u->right=NULL;
    u->v=x;
    return u;
}

node* creat(int *pre,int l1,int *mid,int l2){
    int i,j,k;
    for(i=0;i<l2;i++)
        if(pre[0]==mid[i]) break;
    node* u=newNode(mid[i]);
    if(i>0)
        u->left=creat(pre+1,i,mid,i);       //重点理解这两个if就好了
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

int f;

void print(node* u){
    if(u==NULL) return ;
    print(u->left);
    print(u->right);
    if(f)
        printf(" ");
    f=1;
    printf("%d",u->v);
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            scanf("%d",&pre[i]);
        for(i=0;i<n;i++)
            scanf("%d",&mid[i]);
        remove_tree(root);
        root=creat(pre,n,mid,n);
        f=0;
        print(root);
        printf("\n");
    }
    return 0;
}
