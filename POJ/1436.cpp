#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=8000*2+10;
int cover[maxn*4];

struct pp
{
    int y0,y1,x;
}s[8000];

int cmp(const pp &a,const pp &b){
    return a.x<b.x;
}

void build(int k,int l,int r){
    cover[k]=-1;
    if(l==r)return ;
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
}

void pushDown(int k){
    if(cover[k]!=-1){
        cover[k*2]=cover[k*2+1]=cover[k];
        cover[k]=-1;
    }
}

void update(int a,int b,int k,int l,int r,int c){
    if(a<=l && r<=b){
        cover[k]=c;return;
    }
    int m=(l+r)/2;
    pushDown(k);
    if(a<=m)
        update(a,b,k*2,l,m,c);
    if(b>m)
        update(a,b,k*2+1,m+1,r,c);
}

bool vis[8001][8001];

void query(int a,int b,int k,int l,int r,int id){
    if(cover[k]!=-1){
        vis[id][cover[k]]=true;return;
    }
    if(l==r)return;
    int m=(l+r)/2;
    pushDown(k);
    if(a<=m)
        query(a,b,k*2,l,m,id);
    if(b>m)
        query(a,b,k*2+1,m+1,r,id);
}

int main()
{
    int i,j,k,T,res,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d%d",&s[i].y0,&s[i].y1,&s[i].x);
            s[i].y0*=2;s[i].y1*=2;
        }
        sort(s,s+n,cmp);
        build(1,0,16000);
        memset(vis,false,sizeof(vis));
        for(i=0;i<n;i++){
            query(s[i].y0,s[i].y1,1,0,16000,i);
            update(s[i].y0,s[i].y1,1,0,16000,i);
        }
        res=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
            if(vis[i][j]){
                for(k=0;k<n;k++){
                    if(vis[i][k] && vis[j][k])
                        res++;
                }
            }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
