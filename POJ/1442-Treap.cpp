/*#include <stdio.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <algorithm>*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn=444444;
const int INF=0x3f3f3f3f;
int a[33000],b[33000];


struct Treap{
    int root,treapCnt,tot,key[maxn],cnt[maxn],pri[maxn],chi[maxn][2],Size[maxn];

    Treap(){
        root=0;treapCnt=1;pri[0]=INF;Size[0]=0;
    }

    void update(int x){
        Size[x]=Size[chi[x][0]]+cnt[x]+Size[chi[x][1]];
    }

    void Rotate(int &x,int t){
        int y=chi[x][t];
        chi[x][t]=chi[y][1-t];
        chi[y][1-t]=x;
        update(x);update(y);
        x=y;
    }

    void _insert(int &x,int v){
        if(x){
            if(key[x]==v) cnt[x]++;
            else {
                int t=key[x]<v;
                _insert(chi[x][t],v);
                if(pri[chi[x][t]]<pri[x])
                    Rotate(x,t);
            }
        }else {
            x=treapCnt++;key[x]=v;cnt[x]=1;
            pri[x]=rand();chi[x][0]=chi[x][1]=0;
        }
        update(x);
    }

    void _delete(int &x,int v){
        if(key[x]==v){
            if(cnt[x]>1) cnt[x]--;
            else {
                if(chi[x][0]==0 && chi[x][1]==0){
                    x=0;return ;
                }
                int t=pri[chi[x][0]]>pri[chi[x][1]];
                Rotate(x,t);
                _delete(x,v);
            }
        }else
            _delete(chi[x][v>key[x]],v);
        update(x);
    }

    int _getKth(int &x,int k){
        if(k<=Size[chi[x][0]])
            return _getKth(chi[x][0],k);
        k-=Size[chi[x][0]]+cnt[x];
        if(k<=0)
            return key[x];
        return _getKth(chi[x][1],k);
    }

    void Insert(int v){
        _insert(root,v);
    }

    void Delete(int v){
        _delete(root,v);
    }

    int getKth(int k){
        return _getKth(root,k);     //我就这里少写了return，WA到死，Debug无数,...!!!!
    }                               //但我一直没写return，为啥样例都过能输出呢。。。。。。。。
}treap;


int main()
{
    int i,n,m,now=1;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
        for(;now<=x;now++)
            treap.Insert(a[now]);
        printf("%d\n",treap.getKth(i));
    }
    return 0;
}
