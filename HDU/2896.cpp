/*
AC自动机
模式匹配时，统计单词节点后并不把val置零，因为
这是多串匹配多串。   这样的话只需要用vector
记录匹配成功的串的编号，输出的时候去重一下就行了。
2A，注意字符不单是小写，改一下idx函数就好了。
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn=100000+5;
const int maxm=1000+5;
const int maxl=10000+5;
const int sigma_size=130;
int n,m;
vector<int> rec[maxm];

typedef struct AhoCorasickAutomata {
    int chi[maxn][sigma_size];
    int fail[maxn];
    int val[maxn];
    int Size;
    void init(){
        Size=1;memset(chi[0],0,sizeof(chi[0]));
    }
    int idx(char c) { return c-31; }        //注意这里就是了

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
            if(u){ que.push(u);fail[u]=0;}
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

    void Find(char *s,vector<int> &ans){
        int i,n,now=0;
        n=strlen(s);
        for(i=0;i<n;i++){
            int d=idx(s[i]);
            while(now && !chi[now][d])
                now=fail[now];
            now=chi[now][d];
            int t=now;
            while(t && val[t]){
                ans.push_back(val[t]);
                t=fail[t];
            }
        }
    }
}AhoCorasickAutomata;

AhoCorasickAutomata ac;
char str[maxl],s[205];

int main()
{
    int i,j,res,tot;
    ac.init();
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",s);
        ac.Insert(s,i+1);
    }
    ac.get_next();
    scanf("%d",&m);
    tot=0;
    for(i=1;i<=m;i++){
        scanf("%s",str);
        ac.Find(str,rec[i]);
    }
    for(i=1;i<=m;i++){
        if(rec[i].size()){
            tot++;printf("web %d:",i);
            sort(rec[i].begin(),rec[i].end());
            int t=unique(rec[i].begin(),rec[i].end())-rec[i].begin();
            for(j=0;j<t;j++) printf(" %d",rec[i][j]);
            printf("\n");
        }
    }
    printf("total: %d\n",tot);
    return 0;
}
