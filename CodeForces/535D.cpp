/****************
*PID:535d div2
*Auth:Jonariguez
*****************
ȷ����s��ÿ��λ�ã���û��ȷ����λ�õĸ���Ϊcnt��
��ô�𰸾���26^cnt��
�����ȷ��ÿ��λ�õ��ַ�ʱ���ֳ�ͻ�������0
������λ�ò��ص�ʱif(x[i-1]+len<=x[i])����ôֱ��ȷ��
���ɣ�  ������ص�����Ҫ����KMP�㷨Ԥ����Ȼ���ж�
�Ƿ�����ص�
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef __int64 LL;

const int maxn=1000000+10;
const int MOD=1e9+7;
char s[maxn];
int vis[maxn],vis1[maxn],x[maxn],next[maxn];

void getFail(char *p,int *f){
    int m=strlen(p);
    f[0]=f[1]=0;
    for(int i=1;i<m;i++){
        int j=f[i];
        while(j && p[i]!=p[j]) j=f[j];
        f[i+1]=p[i]==p[j]?j+1:0;
    }
    memset(vis1,0,sizeof(vis1));
    int now=m;
    while(now){
        vis1[now]=1;
        now=f[now];
    }
}

int main()
{
    int i,j,n,m,p;
    while(scanf("%d%d",&n,&m)!=EOF){
        scanf("%s",s);
        for(i=0;i<m;i++)
            scanf("%d",&x[i]);
        sort(x,x+m);
        int flag=1;
        getFail(s,next);
        p=strlen(s);
        memset(vis,0,sizeof(vis));
        for(i=0;i<m;i++){
            if(i==0 || x[i]-x[i-1]>=p)
                for(j=x[i];j<x[i]+p;j++) vis[j]=1;
            else {
                if(vis1[x[i-1]+p-x[i]])
                    for(j=x[i-1]+p;j<x[i]+p;j++) vis[j]=1;
                else {
                    flag=0;break;
                }
             /*   for(j=u;j<u+p;j++){
                    if(vis[j] && vis[j]!=(s[j-u+1]-'a'+1)){
                        flag=0;break;
                    }else {
                        vis[j]=s[j-u+1]-'a'+1;
                    }
                }*/
            }
        }
        if(!flag){
            printf("0\n");continue;
        }
        LL res=1;
        for(i=1;i<=n;i++)
            if(!vis[i])
                res=(res*26)%MOD;
        printf("%I64d\n",res);
    }
    return 0;
}
