/*
��ʶ�߶���
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int maxn=10000+10;
int x[maxn],y[maxn];

//�߶εĸ������ֵΪmaxn����һ���߶������㣬�����ɢ�ؼ����Ļ���Ҳ�ô����Ҫ2*maxn�ĵ㣬��������maxnҪ�˴�һ��
int cover[maxn*8];

void pushDown(int k){
    if(cover[k]>=0){
        cover[k*2]=cover[k*2+1]=cover[k];
        cover[k]=-1;
    }
}

void Insert(int a,int b,int c,int k,int l,int r){
    if(cover[k]==c) return ;
    if(a<=l && b>=r){           //���������жϲ�����a==l && b==r ����ΪҪ��Ҫ�����������
        cover[k]=c;return ;
    }
    pushDown(k);
    int m=(l+r)/2;
    if(a<=m)
        Insert(a,b,c,k*2,l,m);
    if(b>m)
        Insert(a,b,c,k*2+1,m+1,r);
}

int cnt[maxn];

void query(int k,int l,int r){
    if(cover[k]>=0){
        cnt[cover[k]]=1;return ;
    }
    if(l==r) return ;
    pushDown(k);
    int m=(l+r)/2;
    query(k*2,l,m);
    query(k*2+1,m+1,r);
}

unsigned short mark[10000002];  //ԭ��unsigned short��16λ�����Կ��ܴ��.��ʵ��bool��8λ�����Կ�����ģ�
                                //���Ǵ�����滹��mark[temp[i]]=i+1;�����Բ�����bool��
int temp[maxn*2];

int main()
{
    int i,j,k,T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        //��ɢ��
        memset(mark,0,sizeof(mark));
        int tot=0;
        for(i=0;i<n;i++){
            scanf("%d%d",&x[i],&y[i]);
            if(mark[x[i]]==0){
                mark[x[i]]=1;
                temp[tot++]=x[i];
            }
            if(mark[y[i]]==0){
                mark[y[i]]=1;
                temp[tot++]=y[i];
            }
        }
        sort(temp,temp+tot);
        for(i=0;i<tot;i++)
            mark[temp[i]]=i+1;
        for(i=0;i<n;i++)
            Insert(mark[x[i]],mark[y[i]],i,1,1,tot);    //mark[x[i]]�����߶ε���˵���ɢ����ı�ţ����ϴ��ύAC����Ķ���
        memset(cnt,0,sizeof(cnt));
        query(1,1,tot);
        int sum=0;
        for(i=0;i<=n;i++)       //ע��������ѭ����n����tot
            sum+=cnt[i];
        printf("%d\n",sum);
    }
    return 0;
}

