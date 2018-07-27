#include <stdio.h>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

const int maxn=150*75+10;
const int maxl=1000000+10;
char str[maxl],word[155][80];

map<string,int> mp;

typedef struct AhoCorasickAutomata{
    int chi[maxn][26];
    int fail[maxn];
    int val[maxn];
    int cnt[160];
    int last[maxn];
    int Size;

    void init(){
        Size=1;memset(chi[0],0,sizeof(chi[0]));memset(val,0,sizeof(val));
        memset(cnt,0,sizeof(cnt));mp.clear();
    }

    int idx(char c) { return c-'a'; }

    void Insert(char *s,int v){
        int i,n,now=0;
        n=strlen(s);
        for(i=0;i<n;i++){
            int id=idx(s[i]);
            if(chi[now][id]==0){
                memset(chi[Size],0,sizeof(chi[Size]));
                chi[now][id]=Size++;
            }
            now=chi[now][id];
        }
        val[now]=v;
        mp[string(s)]=v;
    }

    void print(int j){
        if(j){
            cnt[val[j]]++;
            print(last[j]);
        }
    }

    void get_fail(){
        queue<int> que;
        fail[0]=0;
        int i;
        for(i=0;i<26;i++){
            int u=chi[0][i];
            if(u){
                que.push(u);fail[u]=0;last[u]=0;
            }
        }
        while(!que.empty()){
            int p=que.front();que.pop();
            for(int c=0;c<26;c++){
                int u=chi[p][c];
                if(!u) continue;
                que.push(u);
                int v=fail[p];
                while(v && !chi[v][c]) v=fail[v];
                fail[u]=chi[v][c];
                last[u] = val[fail[u]] ? fail[u] : last[fail[u]];
            }
        }
    }

    void Find(char *s){
        int i,n,now=0;
        n=strlen(s);
        for(i=0;i<n;i++){
            int id=idx(s[i]);
            while(now && !chi[now][id])
                now=fail[now];
            now=chi[now][id];

            if(val[now]) print(now);
            else if(last[now]) print(last[now]);
        }
    }
}AhoCorasickAutomata;

AhoCorasickAutomata ac;

int main()
{
    int i,j,n,best;
    while(scanf("%d",&n),n){
        ac.init();
        for(i=1;i<=n;i++){
            scanf("%s",word[i]);
            ac.Insert(word[i],i);
        }
        ac.get_fail();
        scanf("%s",str);
        ac.Find(str);
        best=-1;
        for(i=1;i<=n;i++)
            best=max(best,ac.cnt[i]);
        printf("%d\n",best);
        for(i=1;i<=n;i++)
            if(ac.cnt[mp[string(word[i])]]==best)
                printf("%s\n",word[i]);
    }
    return 0;
}
