/*
Trie
���Ȳ����ʱ��res��+=val[0]�������
Ҫ������ַ���Ҫ���Ѿ���������д����Ƚ�
һ��(s[0]==t[0]),�����Ƚ�һ��֮����ô
�Ժ�ÿ�αȽ϶������Σ�
�� if(s[i]=='\0') �� i++��s[i]==t[i]
����res�ӵ�ʱ��val[now]Ҫ*2��

ע��Trie���#forѭ���ĵط���
1�����ѭ����n��˵������ʱ�ǰѽ�����'\0'�����ַ�����ģ�
��ô�����Ծͻ���ִ�Тٶ��˳�������Ģڲ�ִ�У������ǵĳ���
��res�ӵ���val[now]��2������������Ҫ��ȥ�ڵ����������ȥ
End[now].
2�����ѭ����n-1��˵��ֻ�����ϴεĢ�,����εĢ�û��ִ�У�
�����End[now]��
��End[now]����˼�������Ѳ��봮�к�Ŀǰ���봮��ȵĴ��ĸ���
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
        res+=val[0];        //��Ȼ0������ڵ㣬val[0]��ʾ����һ���ж��ٴ�������һ��ʼ�벻��ȡ�
        val[0]++;           //���㲻���ҲҪ�Ƚ�һ�µġ�
        n=strlen(s);
        for(i=0;i<=n;i++){      //#
            bool found=false;
            for(v=son[now];v!=0;v=bro[v])
                if(ch[v]==s[i]){
                    found=true; break;
                }
            if(!found){          //���û�ҵ�,�򿪱�һ���µĽڵ㣬һ�������ʽ����son[now]�ĺ�����Ϊnow�ĺ���
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
        if(End[now])            //����кͱ��ַ���s��ȫ��ͬ�Ĵ�����ô�����Ƚ�һ��(if(s[i]=='0')),
            res-=End[now];      //����һ����Ƚ�End�Ρ�(End���Ǳ�����ߵ�now�������ַ�������
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



