/****************
*PID:
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

const int maxn=10000+10;
int post[maxn],mid[maxn],n,res,ans;

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
    int x=post[l2-1],i;
    for(i=0;i<l1;i++) if(x==mid[i]) break;
    node* u=newNode(x);
    if(i>0)
        u->left=creat(mid,i,post,i);
    if(i<l2-1)
        u->right=creat(mid+i+1,l1-i-1,post+i,l2-i-1);
    return u;
}

void remove_tree(node* r){
    if(r==NULL) return ;
    remove_tree(r->left);
    remove_tree(r->right);
    delete r;
}

bool read(int *a){
    string line;
    if(!getline(cin,line)) return false;
    stringstream ss(line);
    n=0;
    int x;
    while(ss>>x)
        a[n++]=x;
    return n>0;
}

void dfs(node* u,int sum){
    if(u->left==NULL && u->right==NULL){
        sum+=u->v;
        if(sum<res || res==sum && u->v<ans){
            res=sum;ans=u->v;
        }
        return ;
    }
    if(u->left)
        dfs(u->left,sum+u->v);
    if(u->right)
        dfs(u->right,sum+u->v);
}

int main()
{
    int i,j;
    while(read(mid)){
        read(post);
        remove_tree(root);
     //   for(i=0;i<n;i++)
     //       printf("%d ",mid[i]);
     //   printf("??\n");
      //  root=(node*)malloc(sizeof(node));
        root=creat(mid,n,post,n);
        res=1e9;ans=1e9;
        dfs(root,0);
        printf("%d\n",ans);
    }
    return 0;
}

