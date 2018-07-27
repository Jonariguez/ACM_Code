/*
中序+后序构造树
形参的int* post的方式使这些处理起来
简洁很多。
*/
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int post[10100],mid[10100],n;

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

node* creat(int *mid,int l1,int *post,int l2){
    int i,j,k;
    for(i=0;i<l1;i++)
        if(post[l2-1]==mid[i]) break;
    node* u=newNode(mid[i]);
    if(i>0)
        u->left=creat(mid,i,post,i);
    if(i<l2-1)
        u->right=creat(mid+i+1,l1-i-1,post+i,l2-i-1);
    return u;
}

void remove_tree(node* u){
    if(u==NULL) return ;
    remove_tree(u->left);
    remove_tree(u->right);
    delete u;
}

int sum,minv,k;

void dfs(node* u){
    sum+=u->v;          //注意是递归进入时sum就更新，最后退出时再减掉
    if(u->left==NULL && u->right==NULL){
        if(minv>sum || minv==sum && u->v<k){
            minv=sum;k=u->v;
        }
    }
    if(u->left)  dfs(u->left);
    if(u->right) dfs(u->right);
    sum-=u->v;
}


bool input(int *a){
    string line;
    if(!getline(cin,line))
        return false;
    stringstream ss(line);
    int x;
    n=0;
    while(ss>>x)
        a[n++]=x;
    return n>0;
}

int main()
{
    int i,j,res;
    while(input(mid)){
        input(post);
        remove_tree(root);
        root=creat(mid,n,post,n);
        sum=0;
        k=10000+10;minv=10000*10000+10;
        dfs(root);
        printf("%d\n",k);
    }
    return 0;
}
