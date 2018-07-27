/*
AC�Զ���ģ��
���������

#��ע�״��
*/
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn=500000+10;
const int maxl=1000000+10;

typedef struct AhoCorasickAutomata{
    int chi[maxn][26];
    int fail[maxn];
    int val[maxn];
    int Size;
    int res;

    void init(){
        Size=1;memset(chi[0],0,sizeof(chi[0]));
        memset(val,0,sizeof(val));res=0;
    }

    int idx(char c) { return c-'a'; }

    void Insert(char *s){
        int i,n,now=0;
        n=strlen(s);
        for(i=0;i<n;i++){
            int id=idx(s[i]);
            if(chi[now][id]==0){
                memset(chi[Size],0,sizeof(chi[Size]));      //#,chi[now]
                chi[now][id]=Size++;
            }
            now=chi[now][id];
        }
        val[now]++;
    }

    void get_fail(){
        queue<int> que;
        fail[0]=0;
        int i;
        for(i=0;i<26;i++){
            int u=chi[0][i];
            if(u){
                fail[u]=0;que.push(u);
            }
        }
        while(!que.empty()){
            int r=que.front();que.pop();
            for(int c=0;c<26;c++){
                int u=chi[r][c];
                if(!u) continue;
                que.push(u);            //#,��ʱ����
                int v=fail[r];
                while(v && !chi[v][c]) v=fail[v];
                fail[u]=chi[v][c];              //# fail[v]
            }
        }
    }

    void Find(char *s){
        int i,n,now=0;
        n=strlen(s);
        for(i=0;i<n;i++){
            int id=idx(s[i]);
            while(now && !chi[now][id]){
                now=fail[now];
            }
            now=chi[now][id];
       //     printf("val=%d,s[i]=%c\n",val[now],s[i]);
            int t=now;
            while(t && val[t]!=-1){ //���������ǣ������now����s[i]�ַ�ƥ�����ˣ���ô�ͼ��Ŀǰ���ĺ�׺��
                res+=val[t];val[t]=-1;t=fail[t];    //���Ƿ��е��ʽڵ㣬�еĻ��Ϳ϶��Ǳ������˵ģ�����Ҫͳ�Ʋ�����
            }
        }
    }
}AhoCorasickAutomata;

AhoCorasickAutomata ac;
char str[maxl],word[100];

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        ac.init();
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%s",word);
            ac.Insert(word);
        }
        ac.get_fail();
        scanf("%s",str);
        ac.Find(str);
        printf("%d\n",ac.res);
    }
    return 0;
}
