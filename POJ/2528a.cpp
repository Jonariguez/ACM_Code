#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

//��ʵ��ɢ���ܹ��ĵ�λ�������ɴﵽ20000+19999��
//����cover����maxn*2*2*4
const int maxn=10000+10;
int cover[maxn*16],x[maxn],y[maxn],s[maxn*2];
unsigned short Hash[10000005];      //unsigned short�Ź��ã�short�����ã���re

void pushDown(int k){
    if(cover[k]>=0){
        cover[k*2]=cover[k*2+1]=cover[k];
        cover[k]=-1;
    }
}

void Insert(int a,int b,int c,int k,int l,int r){
    if(a<=l && r<=b){
        cover[k]=c;return ;
    }
    pushDown(k);
    int m=(l+r)/2;
    if(a<=m)
        Insert(a,b,c,k*2,l,m);
    if(b>m)
        Insert(a,b,c,k*2+1,m+1,r);
}

bool vis[maxn];

void ask(int k,int l,int r){
    if(cover[k]>=0){
        vis[cover[k]]=true;
        return ;
    }
    if(l==r) return ;
    pushDown(k);
    int m=(l+r)/2;
    ask(k*2,l,m);
    ask(k*2+1,m+1,r);
}

int main()
{
    int i,T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(Hash,0,sizeof(Hash));
        int tot=0;
        for(i=0;i<n;i++){
            scanf("%d%d",&x[i],&y[i]);
            if(Hash[x[i]]==0){
                s[tot++]=x[i];
                Hash[x[i]]++;
            }
            if(Hash[y[i]]==0){
                s[tot++]=y[i];
                Hash[y[i]]++;
            }
        }
        sort(s,s+tot);
        int m=1;
        for(i=0;i<tot;i++){
            Hash[s[i]]=m;
            if(i<tot-1){
                if(s[i+1]-s[i]==1)  //���ԭ����(x[],y[])�����ڵ�(����ֵΪ1),��ô��ɢ��Ҳ�����ڵ�(����ֵҲΪ1)
                    m++;
                else
                    m+=2; //���ԭ���겻�����ڵ�(����ֵ����1),��ô��ɢҲ�����ڣ��м�Ҫ��һ����λ����(����Ҫ��2)
            }
        }
        memset(cover,-1,sizeof(cover));
        cover[1]=0;
        for(i=0;i<n;i++)
            Insert(Hash[x[i]],Hash[y[i]],i+1,1,1,m);
        memset(vis,false,sizeof(vis));
        ask(1,1,m);
        int res=0;
        for(i=1;i<=n;i++)
            if(vis[i]) res++;
        printf("%d\n",res);
    }
    return 0;
}

