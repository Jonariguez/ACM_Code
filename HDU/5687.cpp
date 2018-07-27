/****************
*PID:hdu5687
*Auth:Jonariguez
*****************
字典树
注意：对于不存在的前缀，delete操作不执行。
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;

typedef struct TRIE{
    int chi[maxn*30][26],val[maxn*30],Size;
    void Init(){
        memset(chi[0],0,sizeof(chi[0]));
        memset(val,0,sizeof(val));
        Size=1;
    }
    void Insert(char *str){
        int n=strlen(str),now=0;
        for(int i=0;i<n;i++){
            int id=(str[i]-'a');
            if(chi[now][id]==0){
                memset(chi[Size],0,sizeof(chi[Size]));
                chi[now][id]=Size++;
            }
            now=chi[now][id];
            val[now]++;
        }
    }
    bool Have(char *str){
        int n=strlen(str),i,now=0;
        for(i=0;i<n;i++){
            int id=(str[i]-'a');
            if(chi[now][id]==0) return false;
            now=chi[now][id];
            if(val[now]==0) return false;
        }
        return true;
    }
    void Delete(char *str){
        int n=strlen(str),i,now=0,res;
        for(i=0;i<n;i++){
            int id=(str[i]-'a');
            now=chi[now][id];
          //  val[now]=0;
        }
        res=val[now];
        now=0;
        for(i=0;i<n;i++){
            int id=(str[i]-'a');
            now=chi[now][id];
            val[now]-=res;
        }
        memset(chi[now],0,sizeof(chi[now]));
    }
    bool ask(char *str){
        int n=strlen(str),i,now=0;
        for(i=0;i<n;i++){
            int id=(str[i]-'a');
            if(chi[now][id]==0) return false;
            now=chi[now][id];
            if(val[now]==0) return false;
        }
        return true;
    }
}Trie;

Trie trie;

char op[10],str[50];

int main()
{
    int i,j,n,T;
    sc(T);
    trie.Init();
    while(T--){
        scanf("%s%s",op,str);
        if(op[0]=='i')
            trie.Insert(str);
        else if(op[0]=='d'){
            if(trie.Have(str))
                trie.Delete(str);
        }else {
            if(trie.ask(str))
                puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
