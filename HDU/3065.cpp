/*
AC自动机
我去，题目压根没说是多组数据，我单组数据一直WA。。。。
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxnode=50000+10;
const int maxn=1000+10;
const int maxl=2000000+10;
const int sigma_size=130;
int vis[maxn];

typedef struct AhoCorasickAutomata {
    int chi[maxnode][sigma_size];
    int fail[maxnode];
    int val[maxnode];
    int Size;
    void init(){
        Size=1;memset(chi[0],0,sizeof(chi[0]));
    }
    int idx(char c){ return c-31; }

    void Insert(char *s,int v){
        int i,n,now=0;
        n=strlen(s);
        for(i=0;i<n;i++){
            int d=idx(s[i]);
            if(chi[now][d]==0){
                memset(chi[Size],0,sizeof(chi[Size]));
                val[Size]=0;
                chi[now][d]=Size++;
            }
            now=chi[now][d];
        }
        val[now]=v;
    }

    void get_next(){
        queue<int> que;
        fail[0]=0;
        for(int i=0;i<sigma_size;i++){
            int u=chi[0][i];
            if(u){ que.push(u); fail[u]=0; }
        }
        while(!que.empty()){
            int r=que.front();que.pop();
            for(int c=0;c<sigma_size;c++){
                int u=chi[r][c];
                if(!u) continue;
                que.push(u);
                int v=fail[r];
                while(v && !chi[v][c]) v=fail[v];
                fail[u]=chi[v][c];
            }
        }
    }

    void Find(char *s){
        int i,n,now=0;
        n=strlen(s);
        for(i=0;i<n;i++){
            int d=idx(s[i]);
            while(now && !chi[now][d])
                now=fail[now];
            now=chi[now][d];
            int t=now;
            while(t){
                vis[val[t]]++;
                t=fail[t];
            }
        }
    }
}AhoCorasickAutomata;

AhoCorasickAutomata ac;
char str[maxl],vir[maxn][55];

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        ac.init();
        for(i=1;i<=n;i++){
            scanf("%s",vir[i]);
            ac.Insert(vir[i],i);
        }
        ac.get_next();
        scanf("%s",str);
        memset(vis,0,sizeof(vis));
        ac.Find(str);
        for(i=1;i<=n;i++)
            if(vis[i])
                printf("%s: %d\n",vir[i],vis[i]);
    }
    return 0;
}
