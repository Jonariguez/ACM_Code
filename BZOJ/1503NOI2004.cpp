#include <stdio.h>
#include <string.h>
#define nil 0
const int maxn=100000+10;

int key[maxn],size[maxn],left[maxn],right[maxn];
int T,node;
int n,min,add,I;

void Left_Rotate(int &x){
    int k=right[x];
    right[x]=left[k];
    left[k]=x;
    size[k]=size[x];
    size[x]=size[left[x]]+size[right[x]]+1;
    x=k;
}

void Right_Rotate(int &x){
    int k=left[x];
    left[x]=right[k];
    right[k]=x;
    size[k]=size[x];
    size[x]=size[left[x]]+size[right[x]]+1;
    x=k;
}

void maintain(int &T,bool flag);

void Insert(int &T,int v){
    if(T==nil){
        key[T=++node]=v;
        size[T]=1;
        left[T]=right[T]=nil;
    }else {
        size[T]++;
        if(v<key[T])
            Insert(left[T],v);
        else
            Insert(right[T],v);
        maintain(T,v>=key[T]);
    }
}

int Delete(int &T,int v){
    size[T]--;
    if((v==key[T]) || (v<key[T] && left[T]==nil) || (v>key[T] && right[T]==nil)){
        int r=key[T];
        if(left[T]==nil || right[T]==nil)
            T=left[T]+right[T];
        else
            key[T]=Delete(left[T],key[T]+1);        //key[T]+1可以看出“后一个”
        return r;
    }else {
        if(v<key[T])
            return Delete(left[T],v);
        else
            return Delete(right[T],v);
    }
}

void Clear(int &T){
    if(T==nil)
        return ;
    Clear(left[T]);
    Clear(right[T]);
    size[T]=0;T=nil;
    key[T]=left[T]=right[T]=0;
}

int Erase(int &T,int v){
    if(T==nil)
        return T;       //我感觉是return 0;的意思
    int r=0;
    if(key[T]<v){
        r=size[left[T]]+Erase(right[T],v);      //r代表要檫除的节点个数
        Clear(left[T]);         //如果key[T]<k的话，那么T的左子树的key都要小于k，故要整个树都删除
        size[T]-=r;
        Delete(T,key[T]);       //把当前的节点删掉
        return r+1;
    }else {
        r=Erase(left[T],v);
        size[T]-=r;
        return r;
    }
}

void maintain(int &T,bool flag){
    if(flag==false){
        if(size[left[left[T]]] > size[right[T]])
            Right_Rotate(T);
        else {
            if(size[right[left[T]]]>size[right[T]]){
                Left_Rotate(left[T]);
                Right_Rotate(T);
            }else return ;
        }
    }else {
        if(size[right[right[T]]]>size[left[T]])
                Left_Rotate(T);
        else {
            if(size[left[right[T]]] > size[left[T]]){
                    Right_Rotate(right[T]);
                    Left_Rotate(T);
            }else return ;
        }
    }
    maintain(left[T],false);
    maintain(right[T],true);
    maintain(T,true);
    maintain(T,false);
}

int select(int T,int k){
    int r=size[left[T]]+1;
    if(k==r) return key[T];
    else if(k<r)
        return select(left[T],k);
    else
        return select(right[T],k-r);
}

int main()
{
    int i,k,b,sum,res;
    char s[3];
    scanf("%d%d",&n,&min);
    sum=0;
    while(n--){
        scanf("%s%d",s,&b);
        if(s[0]=='I'){
            if(b>=min){
                Insert(T,b+add);
                sum++;
            }
        }else if(s[0]=='A')
            add-=b;
        else if(s[0]=='S'){
            add+=b;
            Erase(T,min+add);
            maintain(T,true);
            maintain(T,false);
        }else{
            if(b>size[T])
                printf("-1\n");
            else
                printf("%d\n",select(T,size[T]-b+1)-add);
        }
        }
        printf("%d\n",sum-size[T]);
        return 0;
}


