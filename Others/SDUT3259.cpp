/****************
*PID:sdut3259
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+4;

struct Trie{
    int chi[33*maxn][2],Size,val[maxn*33],Bit[maxn*33],Port[maxn*33];
    void Init(){
        chi[0][0]=chi[0][1]=0;Size=1;
        memset(Bit,-1,sizeof(Bit));
    }
    void Insert(LL IP,int num,int port){
        int now=0,i;
        for(i=31;i>=(32-num);i--){
            LL temp=((IP>>i)&1);
            int v=0;
            if(temp) v=1;
            if(chi[now][v]==0){
                memset(chi[Size],0,sizeof(chi[Size]));
                val[Size]=0;
                chi[now][v]=Size++;
            }
            now=chi[now][v];
        }
        val[now]=1;
        if(Bit[now]<num || (Bit[now]==num && Port[now]>port)){
            Bit[now]=num;Port[now]=port;
        }
    }
    int ask(LL IP){
        int now=0,i,res=-1,bit=-1;
        for(i=31;i>=0;i--){
            if(val[now]){
                if(bit<Bit[now] || (bit==Bit[now] && res>Port[now])){
                    bit=Bit[now];res=Port[now];
                }
            }
            LL temp=((IP>>i)&1);
            int v=0;
            if(temp) v=1;
            if(chi[now][0]==0 && chi[now][1]==0)
                return res;
            if(chi[now][v^1] && chi[now][v]==0)
                return res;
            now=chi[now][v];
        }
        if(val[now]){
            if(bit<Bit[now] || (bit==Bit[now] && res>Port[now])){
                bit=Bit[now];res=Port[now];
            }
        }
        return res;
    }
}trie;

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        trie.Init();
        LL x,temp;
        int cnt,port;
        for(i=1;i<=n;i++){
            x=0;
            scanf("%I64d.",&temp);
           // printf("temp=%I64d\n",temp);
            x|=(temp<<24);
            scanf("%I64d.",&temp);
            x|=(temp<<16);
            scanf("%I64d.",&temp);
            x|=(temp<<8);
            scanf("%I64d/%d",&temp,&cnt);
            x|=temp;
            scanf("%d",&port);
            trie.Insert(x,cnt,port);
        };
        while(m--){
            x=0;
            scanf("%I64d.",&temp);
            x|=(temp<<24);
            scanf("%I64d.",&temp);
            x|=(temp<<16);
            scanf("%I64d.",&temp);
            x|=(temp<<8);
            scanf("%I64d",&temp);
            x|=temp;
            int res=trie.ask(x);
            if(res==-1)
                puts("65535");
            else printf("%d\n",res);
        }
    }
    return 0;
}
