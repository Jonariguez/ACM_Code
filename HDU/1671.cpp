/*
Trie树
一定要先插入短的，因为长的号码不可能是
短号码的前缀。
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=500000+10;
bool yes;

struct Str{
    int len;
    char ss[11];
}s[10005];

int cmp(const Str &x,const Str &y){
    if(x.len==y.len)
        return strcmp(x.ss,y.ss)<0;
    return x.len<y.len;
}

typedef struct Trie{
    int chi[maxn][11];
    int val[maxn];
    int Size;

    void Init(){ Size=1;memset(chi[0],0,sizeof(chi[0]));memset(val,0,sizeof(val));}
    int idx(char c) { return c-'0'; }

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
            if(val[now]) yes=false;
        }
        val[now]=1;
    }
}Trie;

Trie T;

int main()
{
    int i,n,t;
    char str[11];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%s",str);
            s[i].len=strlen(str);
            strcpy(s[i].ss,str);
        }
        sort(s,s+n,cmp);
        T.Init();
        yes=true;
        for(i=0;i<n;i++){
            if(!yes) continue;  //优化一下
            T.Insert(s[i].ss);
        }
        if(yes)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
