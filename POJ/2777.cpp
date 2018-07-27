#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
int cover[maxn*4],color[maxn*4];
int t;

void pushUp(int k){
    color[k]=color[k*2]|color[k*2+1];
}

void pushDown(int k){
    if(cover[k]>0){           //难道是这里不能写>0
        cover[k*2]=cover[k*2+1]=cover[k];
        color[k*2]=color[k*2+1]=color[k];
        cover[k]=0;
    }
}

void build(int k,int l,int r){
    if(l==r){
        color[k]=1;return ;     //难道是这里非要要写成color|=1。  不是
    }
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    pushUp(k);
}

void Insert(int a,int b,int c,int k,int l,int r){
    if(a<=l && b>=r){
        cover[k]=1;color[k]=(1<<(c-1));return ;
    }
    pushDown(k);
    int m=(l+r)/2;
    if(a<=m)
        Insert(a,b,c,k*2,l,m);
    if(b>m)
        Insert(a,b,c,k*2+1,m+1,r);
    pushUp(k);
}

int res;

int ask(int a,int b,int k,int l,int r){
    if(a<=l && r<=b){
        return color[k];
    }
    pushDown(k);
    int m=(l+r)/2,ans=0;
    if(a<=m)
        ans|=ask(a,b,k*2,l,m);
    if(b>m)
        ans|=ask(a,b,k*2+1,m+1,r);
    return ans;
}

int main()
{
    int i,n,o,a,c,b;
    char s[4];
    scanf("%d%d%d",&n,&t,&o);
    build(1,1,n);
    while(o--){
        scanf("%s%d%d",s,&a,&b);
        if(a>b){ int d=a;a=b;b=d;}      //就因为这里的';'不能写成','，WA10次
        if(s[0]=='C'){
            scanf("%d",&c);
            Insert(a,b,c,1,1,n);
        }
        else {
            res=ask(a,b,1,1,n);
            int cnt=0;
            while(res){     //难道这里一定要写成for？？？答案：不是
                if(res&1) cnt++;
                res/=2;
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}
