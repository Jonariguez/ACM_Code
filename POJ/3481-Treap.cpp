/*
*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define INF 100000007
#define maxn 440004

struct Treap{
    int root,treapCnt,tot,key[maxn],pri[maxn],chi[maxn][2],cnt[maxn],Size[maxn],num[maxn];

    Treap(){
        root=0;treapCnt=1;tot=0,pri[0]=INT_MAX;Size[0]=0;
    }

    void update(int x){
        Size[x]=Size[chi[x][0]]+cnt[x]+Size[chi[x][1]];
    }

    //t=0,x右旋 t=1，x左旋
    void Rotate(int &x,int t){
        int y=chi[x][t];
        chi[x][t]=chi[y][1-t];
        chi[y][1-t]=x;
        update(x);update(y);
        x=y;
    }

    void _insert(int &x,int k,int p){
        if(x){
            if(key[x]==p)
                cnt[x]++;
            else {
                int t=key[x]<p;
                _insert(chi[x][t],k,p);
                if(pri[chi[x][t]]<pri[x])
                    Rotate(x,t);
            }
        }else {
            x=treapCnt++;
            key[x]=p;cnt[x]=1;pri[x]=rand();
            Size[x]=1;num[x]=k;
            chi[x][0]=chi[x][1]=0;
        }
        update(x);
    }

    void _delete(int &x,int k){
        if(key[x]==k){
            if(cnt[x]>1) cnt[x]--;
            else {
                if(chi[x][0]==0 && chi[x][1]==0){
                    x=0;return ;
                }
                int t=pri[chi[x][0]]>pri[chi[x][1]];
                Rotate(x,t);
                _delete(x,k);
            }
        }else
            _delete(chi[x][key[x]<k],k);
        update(x);
    }

    int _getKth(int &x,int k){
        if(k<=Size[chi[x][0]])
            return _getKth(chi[x][0],k);
        k-=Size[chi[x][0]]+cnt[x];
        if(k<=0){
            printf("%d\n",num[x]);
            return key[x];
        }
        return _getKth(chi[x][1],k);
    }

    bool Empty(){
        return Size[root]==0;
    }

    void Insert(int k,int p){
        _insert(root,k,p);
        tot++;
    }

    void Delete(int k){
        _delete(root,k);
        tot--;
    }

    int getMax(){
        return _getKth(root,tot);
    }

    int getMin(){
        return _getKth(root,1);
    }
}T;

int main()
{
    int i,k,p,x;
    while(scanf("%d",&x),x){
        if(x==0) break;
        if(x==1){
            scanf("%d%d",&k,&p);
            T.Insert(k,p);
        }else if(x==2){
            if(T.Empty()){
                printf("0\n");continue;
            }
            int t=T.getMax();
            T.Delete(t);
        }else {
            if(T.Empty()){
                printf("0\n");continue;
            }
            int t=T.getMin();
            T.Delete(t);
        }
    }

    return 0;
}
