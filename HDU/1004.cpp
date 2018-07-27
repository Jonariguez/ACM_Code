#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
int maxv=0;
char res[20];

struct Trie{
    int chi[maxn][27];
    int val[maxn];
    int Size;
    Trie(){ Size=1;
    memset(chi[0],0,sizeof(chi[0]));memset(val,0,sizeof(val));
    }
    int idx(char c){ return c-'a'; }

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
        }
        val[now]++;
        if(maxv<val[now]){
            maxv=val[now];
            strcpy(res,s);
        }
    }
}T;

int main()
{
    int i,j,n;
    char str[20];
    while(scanf("%d",&n),n){
        maxv=0;
        while(n--){
            scanf("%s",str);
            T.Insert(str);
        }
        printf("%s\n",res);
    }
    return 0;
}
