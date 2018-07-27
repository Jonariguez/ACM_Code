/*
���ַ����¼ӵ�str�У���totΪ�������ָ�롣
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
char str[maxn],s[maxn];
int next[maxn],head,tail,last,cur,tot;
//last���ַ�����λ�ã�cur�ǵ�ǰ
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
                //֮�������ⲽ�ж�����Ϊ�����β����ַ�ʱ��last����cur������Ҫʱʱ����
                //�����curͨ��[����ǰ��ȥ�ˣ���ô�Ͳ��ø���last�ˡ���Ϊ��ʱlast����ĩβ
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
