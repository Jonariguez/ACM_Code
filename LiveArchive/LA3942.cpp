#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=4000*100+10;
const int maxl=300000+10;
const int MOD=20071027;
char str[maxl];
int len[4000+10],d[maxl];

typedef struct Trie{
    int chi[maxn][26],val[maxn],Size;
    void Init(){
        Size=1;memset(chi[0],0,sizeof(chi[0]));
        memset(val,0,sizeof(val));
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
    }

    void Find(char *s,vector<int>& ans){
        int i,n,now=0;
        n=strlen(s);
        for(i=0;i<n;i++){
            int id=idx(s[i]);
            if(chi[now][id]==0) return ;
            now=chi[now][id];
            if(val[now])
                ans.push_back(val[now]);
        }
    }
}Trie;

Trie trie;

int main()
{
    int i,j,n,S,kcase=1;
    char s[110];
    while(scanf("%s%d",str,&S)!=EOF){
        trie.Init();
        for(i=1;i<=S;i++){
            scanf("%s",&s);
            len[i]=strlen(s);
            trie.Insert(s,i);
        }
        memset(d,0,sizeof(d));
        n=strlen(str);
        d[n]=1;
        for(i=n-1;i>=0;i--){
            vector<int> p;
            trie.Find(str+i,p);
            for(j=0;j<p.size();j++)
                d[i]=(d[i]+d[i+len[p[j]]])%MOD;
        }
        printf("Case %d: %d\n",kcase++,d[0]%MOD);
    }
    return 0;
}
