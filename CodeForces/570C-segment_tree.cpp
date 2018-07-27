/****************
*ID:cf570
*Auth:Jonariguez
*****************
sum[k]ά���𰸣�L[k]��ʾk��Ӧ������������ǲ���'.'��R[k]�ĺ�����ͬ
�ϲ�ʱsum[k]=sum[k*2]+sum[k*2+1],��������������ұߺ��������������
����'.'����ôsum[k]�ͼ�1
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=300000+10;
int sum[maxn*4],L[maxn*4],R[maxn*4];

void pushUp(int k){
    int lc=k*2,rc=k*2+1;
    sum[k]=sum[lc]+sum[rc];
    if(R[lc] && L[rc])
        sum[k]++;
    L[k]=L[lc];R[k]=R[rc];
}

void build(int k,int l,int r){
    sum[k]=L[k]=R[k]=0;
    if(l==r){
        char ch;
        scanf(" %c",&ch);
        if(ch=='.'){
            sum[k]=0;
            L[k]=R[k]=1;
        }
        return ;
    }
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    pushUp(k);
}

void update(int a,char ch,int k,int l,int r){
    if(l==r){
        if(ch=='.'){
            sum[k]=0;
            L[k]=R[k]=1;
        }
        else sum[k]=L[k]=R[k]=0;
        return ;
    }
    int m=(l+r)/2;
    if(a<=m)
        update(a,ch,k*2,l,m);
    else
        update(a,ch,k*2+1,m+1,r);
    pushUp(k);
}

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        build(1,1,n);
        while(m--){
            int p;
            char ch;
            scanf("%d %c",&p,&ch);
            update(p,ch,1,1,n);
            printf("%d\n",sum[1]);
        }
    }
    return 0;
}
