#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=1000000+10;
int cover[maxn*4],color[maxn*4];

void pushUp(int k){
    color[k]=color[k*2]|color[k*2+1];
}

void pushDown(int k){
    if(cover[k]){
        cover[k*2]=cover[k*2+1]=cover[k];
        color[k*2]=color[k*2+1]=color[k];
        cover[k]=0;
    }
}

void build(int k,int l,int r){
   // cover[k]=0;color[k]=0;
    if(l==r){
        color[k]=2;return ;
    }
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    pushUp(k);
}

void update(int a,int b,int c,int k,int l,int r){
    if(a<=l && r<=b){
        cover[k]=1;color[k]=(1<<(c-1));return ;
    }
    pushDown(k);
    int m=(l+r)/2;
    if(a<=m)
        update(a,b,c,k*2,l,m);
    if(b>m)
        update(a,b,c,k*2+1,m+1,r);
    pushUp(k);
}

/*
int ans;

void ask(int a,int b,int k,int l,int r){
    if(a<=l && r<=b){
        ans=ans|cover[k];
        return ;
    }
    pushDown(k);
    int m=(l+r)/2;
    if(a<=m)
        ask(a,b,k*2,l,m);
    if(b>m)
        ask(a,b,k*2+1,m+1,r);
  //  pushUp(k);
}*/

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
    int i,j,n,m;
    char op[5];
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        build(1,1,n);
      //  update(1,n,2,1,1,n);
        int l,r,c;
        while(m--){
            scanf("%s%d%d",op,&l,&r);
            if(op[0]=='P'){
                scanf("%d",&c);
                update(l,r,c,1,1,n);
            }else {
                res=ask(l,r,1,1,n);
                int t=1,space=0;
                while(res){
                    if(res&1){
                        if(space) printf(" ");
                        space++;
                        printf("%d",t);
                    }
                    res/=2;t++;
                }
                printf("\n");
            }
        }
    }
    return 0;
}
