/*
将字符重新加到str中，用tot为链表分配指针。
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
char str[maxn],s[maxn];
int next[maxn],head,tail,last,cur,tot;
//last，字符最后的位置，cur是当前
void add(char c){
    str[++tot]=c;
    next[tot]=next[cur];
    next[cur]=tot;
}

int main()
{
    int i,j,n;
    while(scanf("%s",s)!=EOF){
        n=strlen(s);
        head=tot=0;
        tail=-1;
        next[head]=tail;
        last=head;
        cur=head;
        int cnt=0;
        for(i=0;i<n;i++){
            if(s[i]=='[')
                cur=head;
            else if(s[i]==']')
                cur=last;
            else {
                add(s[i]);
                //之所以有这步判断是因为在最结尾添加字符时，last就是cur，所以要时时更新
                //而如果cur通过[调到前面去了，那么就不用更新last了。因为此时last在最末尾
                if(cur==last)
                    last=next[cur];
                cur=next[cur];
            }
        }
        cur=next[head];
        while(cur!=-1){
            printf("%c",str[cur]);
            cur=next[cur];
        }
        printf("\n");
    }
    return 0;
}
