/*
第一个Splay
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int maxn=200000+10;
const int inf  = ~0u>>2;

int key[maxn],left[maxn],right[maxn],par[maxn],tot,root;

void Init(){
    tot=par[1]=left[1]=right[1]=0;
}

/*
下面代码中加注释的地方都是一开始没处理好，都是要双向考虑，一开始处理的时候都是只处理了谁
是谁的孩子(或谁是谁的父亲),而没处理谁是谁的父亲(或儿子),所以有数组静态表示树还是比较麻烦，
重点是麻烦在：别人都是通过标志c=0或c=1来判断是左旋还是右旋，并且把孩子定义成ch[maxn][2]的
方式，直接用来ch[x][c]来旋转，不用判断各种情况。 像我这么写还要把各种情况写出来，融合性不好
*/
void Left_Rotate(int x){
    int y=par[x];
    right[y]=left[x];
    if(left[x]) par[left[x]]=y;
    par[x]=par[y];
    if(par[y]){
        if(key[x]<key[par[y]])  //还有这里也要注意，要判断x是par[y]的左孩子还是右孩子，因为这个不一定。右转相同
            left[par[y]]=x;
        else
            right[par[y]]=x;
    }
    left[x]=y;
    par[y]=x;
}

void Right_Rotate(int x){
    int y=par[x];
    left[y]=right[x];
    if(right[x]) par[right[x]]=y;
    par[x]=par[y];
    if(par[y]){
        if(key[x]<key[par[y]])
            left[par[y]]=x;
        else
        right[par[y]]=x;
    }
    right[x]=y;
    par[y]=x;
}

void splay(int x){
    if(par[x]==0) return ;  //注意，如果本身就是根节点，那么就不用splay了
    int p;
    while(par[x]){
        p=par[x];
        if(par[p]==0){
            if(x==left[p])
                Right_Rotate(x);
            else
                Left_Rotate(x);
            break;
        }
        if(x==left[p]){
            if(p==left[par[p]]){
                Right_Rotate(p);Right_Rotate(x);
            }else{
                Right_Rotate(x);Left_Rotate(x);
            }
        }else {
            if(p==right[par[p]]){
                Left_Rotate(p);Left_Rotate(x);
            }else{
                Left_Rotate(x);Right_Rotate(x);
            }
        }
    }
    root=x;
}

bool Insert(int x,int v,int p){
    if(x==0){
        x=++tot;
        key[x]=v;
        left[x]=right[x]=0;
        par[x]=p;
        if(v<key[p])    //虽然par[x]=p,但是忘了把x设置成p的儿子了。一直错啊。。。
            left[p]=x;
        else right[p]=x;
        splay(x);
        root=x;
        return true;
    }
    if(v==key[x]){
        splay(x);return false;
    }else if(v<key[x])
        Insert(left[x],v,x);
    else
        Insert(right[x],v,x);
}

int BST_Search(int x,int v){
    if(v==key[x]) return x;
    if(v<key[x])
        return BST_Search(left[x],v);
    return BST_Search(right[x],v);
}

int Find(int x,int v){
    int p=BST_Search(x,v);
    splay(p);
    return p;
}

int prev(int x,int v){
    int p=Find(x,v);
    if(left[p]==0) return -inf;
    p=left[p];
    while(right[p]) p=right[p];
 //   splay(p);
    return key[p];
}

int next(int x,int v){
    int p=Find(x,v);
    if(right[p]==0) return inf;
    p=right[p];
    while(left[p]) p=left[p];
 //   splay(p);
    return key[p];
}

int main()
{
    int i,j,n,a,res;
    Init();
    scanf("%d",&n);
    scanf("%d",&a);
    res=abs(a);root=0;
    Insert(root,a,0);
    n--;
    while(n--){
        a=0;
        scanf("%d",&a);
        if(!Insert(root,a,0))       //出现已经存在的波动值肯定就是0了。
            continue;
        int xx,yy;
        xx=prev(root,a);
        yy=next(root,a);
        if(xx==-inf)
            res+=abs(yy-a);
        else if(yy==inf)
            res+=abs(xx-a);
        else res+=min(abs(xx-a),abs(yy-a));
    }
    printf("%d\n",res);
    return 0;
}


