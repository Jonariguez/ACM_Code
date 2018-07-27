/*
第一行的翻译表存在table里，第二行的文串
存在str里。(文串=密文+明文)
我们知道，文串里，密文一定是完整的，明文可能不完整
也可能没有，但两者没有重叠，所以明文的长度不会超过
文串的一半，同样，密文不会少于文串的一半。
就此题，我们的目的是：将密文翻译成明文后，使前面的由密文
翻译成的明文和后面原本的明文匹配的尽量多。
但我们将密文翻译成明文时不能全部都翻译，因为全部翻译
后面的明文就被破坏而消失，因为明文的长度限制，我们就尽量多
的保留明文，即：
把文串的前一半当做密文并翻译成明文，后一半保留当做明文，
然后去KMP匹配，记录匹配的最多的个数。
匹配上的就是密文和明文的对应，没匹配上的只能当做题目
的主人公没能拦截完全，自然按table表，把没匹配上的密文翻译
一下就是了。

k=Next[i]的含义是，在i处失配(T[j]!=P[i])，i该往前调到什么位置，如果
一直k=next[k]，向前迭代的话，形象地想像一下：如果迭代时主串T固定不动
的话，而k不断减小，那么模式串就会不断的被“往后拉，主串和模式串重叠
的长度(指的的在失配位置之前重叠的长度)也越来越短。

这就是下面程序解释，我们是把str的前半部分翻译，并对整个str串求next，
那么我们想要前半部分和后半部分的重叠长度，就要固定一串，然后另k=Next[len]，
然后从最后一直把下面的模式串"拉到两者的重叠部分小于一半"就是了。
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
char table[30],str[maxn],rstr[maxn],mstr[maxn];
int vis[30],mp[30];
int Next[maxn];

void get_next(char *s){
    int i,j,n;
    n=strlen(s);
    Next[0]=Next[1]=j=0;
    for(i=1;i<n;i++){
        while(j && s[j]!=s[i])
            j=Next[j];
        if(s[j]==s[i]) j++;
        Next[i+1]=j;
    }
}

int main()
{
    int i,j,T,n,len;
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",table,str);
        for(i=0;i<26;i++)
            mp[table[i]-'a']=i;
        len=strlen(str);
        strcpy(mstr,str);
        for(i=0;i<len/2;i++)        //mstr只要它前一半的映射
            mstr[i]='a'+mp[str[i]-'a'];
   /*     for(i=(len+1)/2;i<len;i++)  //rstr只要str的后一半
            rstr[i-(len+1)/2]=str[i];
        rstr[i-(len+1)/2]='\0';           //拿mstr和rstr匹配，mstr是模式串
        n=strlen(mstr);   */
        get_next(mstr);
    /*    for(i=0;i<=n;i++) printf("%d ",Next[i]);
        printf("\n");
        printf("rstr=%s\nmstr=%s\n",rstr,mstr);
        printf("k=%d\n",k);*/
        int k=Next[len];
        while(k>len/2)
            k=Next[k];
        printf("%s",str);
        for(i=k;i<len-k;i++)
            printf("%c",'a'+mp[str[i]-'a']);
        printf("\n");
    }
    return 0;
}
