#include <stdio.h>
#include <string.h>

const int maxn=30000+10;

typedef struct UFSet{
    int par[maxn],under[maxn],sum[maxn];
    void Init(){
        for(int i=0;i<maxn;i++){
            par[i]=i;under[i]=0;sum[i]=1;
        }
    }
    int Find(int x){
        if(par[x]==x) return x;
        int t=Find(par[x]);         //注意这里是先递归Find，然后进行under的路径压缩，不然先执行under后递归的话，起不到压缩的作用
        under[x]+=under[par[x]];
      //  return par[x]=Find(par[x]);
        return par[x]=t;
    }
    void Union(int u,int v){
        if((u=Find(u))==(v=Find(v))) return ;
        under[v]+=sum[u];
      //  under[u]=0;
        sum[u]+=sum[v];
        par[v]=u;
    }
}UFSet;

int main()
{
    int i,p,x,y;
    char s[3];
    scanf("%d",&p);
    UFSet ss;
    ss.Init();
    while(p--){
        scanf("%s",s);
        if(s[0]=='M'){
            scanf("%d%d",&x,&y);
            ss.Union(y,x);
        }
        else{
            scanf("%d",&x);
            ss.Find(x);
            printf("%d\n",ss.under[x]);
        }
    }
    return 0;
}

/*
5
M 2 1
M 4 3
M 7 6
M 3 7
C 4
*/

