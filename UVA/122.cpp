#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//数组不去要开小了
char s[1000];

typedef struct Node{
    int v;
    bool have;
    struct Node *left,*right;
}node;

node *root;

node* newNode(){
    node* u=(node*)malloc(sizeof(node));
    u->left=u->right=NULL;
    u->have=false;
    return u;
}

bool flag;

void add(int v,char *s){
    node* u=root;
    int n=strlen(s);
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            if(u->left==NULL)
                u->left=newNode();
            u=u->left;
        }else if(s[i]=='R'){
            if(u->right==NULL)
                u->right=newNode();
            u=u->right;
        }
    }
    if(u->have)
        flag=false;
    u->v=v;
    u->have=true;
}

void DeleteTree(node* u){
    if(u==NULL) return ;
    DeleteTree(u->left);
    DeleteTree(u->right);
    delete(u);
}

bool input(){
    flag=true;
    DeleteTree(root);
    root=newNode();
    while(true){
        if(scanf("%s",s)!=1) return false;
        if(strcmp(s,"()")==0) break;
        int v;
        sscanf(&s[1],"%d",&v);
        add(v,strchr(s,',')+1);
    }
    return true;
}


vector<int> vec;

bool bfs(){
    vec.clear();
    queue<node*> que;
    que.push(root);
    while(!que.empty()){
        node* u=que.front();que.pop();
        if(u->have==false) return false;
        vec.push_back(u->v);
        if(u->left!=NULL)
            que.push(u->left);
        if(u->right!=NULL)
            que.push(u->right);
    }
    return true;
}

int main()
{
    while(input()){
        if(bfs()==false) flag=false;
        if(!flag)
            printf("not complete\n");
        else {
            for(int i=0;i<vec.size();i++)
                printf("%d%c",vec[i],i==vec.size()-1?'\n':' ');
        }
    }
    return 0;
}


