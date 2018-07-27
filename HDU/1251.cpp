#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=500000+10;

struct Trie{
    int chi[maxn][27];
    int val[maxn];
    int Size;
    Trie(){Size=1;memset(chi[0],0,sizeof(chi[0]));memset(val,0,sizeof(val));}
    int idx(char c) { return c-'a';}

    void Insert(char *s){
        int i,n,now=0;
        n=strlen(s);
        for(i=0;i<n;i++){
            int id=idx(s[i]);
            if(chi[now][id]==0){
                memset(chi[Size],0,sizeof(chi[Size]));
                chi[now][id]=Size++;
            }
            now=chi[now][id];
            val[now]++;         //注意这两句话的位置不能颠倒
        }
    }

    int ask(char *s){
        int i,n,now=0;
        n=strlen(s);
        for(i=0;i<n;i++){
            int id=idx(s[i]);
            if(chi[now][id]==0) return 0;
            now=chi[now][id];
        }
        return val[now];
    }
}T;

char str[12];

int main()
{
    int i,j,n;
    while(gets(str)){
        if(str[0]=='\0') break;
        T.Insert(str);
    }
    while(scanf("%s",str)!=EOF){
        printf("%d\n",T.ask(str));
    }
    return 0;
}
