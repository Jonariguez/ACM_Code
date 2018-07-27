/*
Trie
首先插入的时候res先+=val[0]，这表明
要插入的字符串要和已经插入的所有串都比较
一下(s[0]==t[0]),这样比较一下之后，那么
以后每次比较都是两次：
① if(s[i]=='\0') ② i++后，s[i]==t[i]
所以res加的时候，val[now]要*2。

注意Trie里的#for循环的地方：
1、如果循环到n，说明插入时是把结束符'\0'当做字符处理的，
那么，所以就会因执行①而退出，后面的②不执行，但我们的程序
中res加的是val[now]的2倍，所以我们要减去②的情况，即减去
End[now].
2、如果循环到n-1，说明只处理到上次的②,而这次的①没有执行，
则加上End[now]。
而End[now]的意思就是在已插入串中和目前插入串相等的串的个数
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxnode=4000*1000+10;
const int maxl=1000+10;

typedef struct Trie{
    int son[maxnode];
    int bro[maxnode];
    int val[maxnode];
    int End[maxnode];
    char ch[maxnode];
    int Size;
    long long res;

    void Init(){ Size=1;son[0]=bro[0]=val[0]=End[0]=0; res=0;}

    void Insert(char *s){
        int i,n,v,now=0;
        res+=val[0];        //虽然0不代表节点，val[0]表示的是一共有多少串，不管一开始想不想等。
        val[0]++;           //即便不相等也要比较一下的。
        n=strlen(s);
        for(i=0;i<=n;i++){      //#
            bool found=false;
            for(v=son[now];v!=0;v=bro[v])
                if(ch[v]==s[i]){
                    found=true; break;
                }
            if(!found){          //如果没找到,则开辟一个新的节点，一链表的形式挂在son[now]的后面作为now的孩子
                v=Size++;
                val[v]=End[v]=0;
                ch[v]=s[i];
                bro[v]=son[now];
                son[now]=v;
                son[v]=0;
            }
            now=v;
            res+=val[now]*2;
            val[now]++;
        }
        if(End[now])            //如果有和本字符串s完全相同的串，那么还会多比较一次(if(s[i]=='0')),
            res-=End[now];      //所以一共多比较End次。(End就是标记能走到now结束的字符串个数
        End[now]++;
    }
}Trie;

Trie trie;
char str[maxl];

int main()
{
    int i,j,n,kcase=1;
    while(scanf("%d",&n),n){
        trie.Init();
        while(n--){
            scanf("%s",str);
            trie.Insert(str);
        }
        printf("Case %d: %lld\n",kcase++,trie.res);
    }
    return 0;
}



