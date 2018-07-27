/*
注意在处理操作3时，x和y相邻的情况
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

typedef long long ll;

const int maxn=100000+10;
int pre[maxn],next[maxn],head,tail;

void toLeft(int x,int y){
    next[pre[x]]=next[x];
    pre[next[x]]=pre[x];
    next[x]=y;
    pre[x]=pre[y];
    next[pre[y]]=x;
    pre[y]=x;
}

void toRight(int x,int y){
    next[pre[x]]=next[x];
    pre[next[x]]=pre[x];
    next[x]=next[y];
    pre[x]=y;
    pre[next[y]]=x;
    next[y]=x;
}

void exchange(int x,int y){
    int P=pre[x],N=next[x];
    pre[x]=pre[y];next[x]=next[y];
    next[pre[y]]=pre[next[y]]=x;
    pre[y]=P;next[y]=N;
    next[P]=pre[N]=y;
}

int main()
{
    int i,j,n,m,inv,kcase=1;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++){
            pre[i]=i-1;next[i]=i+1;
        }
        next[n]=pre[1]=0;
        next[0]=1;pre[0]=n;
        head=inv=0;
        while(m--){
            int op,a,b;
            scanf("%d",&op);
            if(op==4)
                inv=!inv;
            else{
                scanf("%d%d",&a,&b);
                if(op==3 && a==next[b])
                    swap(a,b);
                if(op!=3 && inv)
                    op=3-op;
                if(op==1 && pre[b]!=a)
                    toLeft(a,b);
                else if(op==2 && next[b]!=a)
                    toRight(a,b);
                else if(op==3){
                    if(next[a]==b){
                        next[a]=next[b];pre[next[b]]=a;
                        pre[b]=pre[a];next[pre[b]]=b;
                        next[b]=a;pre[a]=b;
                    }
                    else
                        exchange(a,b);
                }
            }
        }
        ll res=0,cnt=1;
        int cur=0;
        cur=next[cur];
        while(cur){
            if(cnt&1) res+=cur;
            cnt++;
            cur=next[cur];
        }
        if(inv && n%2==0)
            res=(ll)n*(n+1)/2-res;
        printf("Case %d: %lld\n",kcase++,res);
    }
    return 0;
}
