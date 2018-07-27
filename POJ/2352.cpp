/*
BIT
һ��ʼ�����ö�άBIT��ά���������鿪���£�������Ҫ��Ҫ��ɢ��һ�¡���
��������������������yһ����x������������ģ����Ա߲���߲�ѯ�Ͷ��ˡ�
����ʵ�������������������ô����Ҳ���԰�y��x����֮���������������һ���ġ��������������ô�������������͸�������
*/
#include <stdio.h>
#include <string.h>

const int maxX=32000+10;
const int N=32001;
const int maxn=15000+10;
int bit[maxX],x[maxn],y[maxn],res[maxn];

void add(int i,int v){
    while(i<=N){
        bit[i]+=v;
        i+=i&(-i);
    }
}

int sum(int i){
    int res=0;
    while(i>0){
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}

int main()
{
    int i,j,n;
    scanf("%d",&n);
    memset(res,0,sizeof(res));
    for(i=0;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
        add(x[i]+1,1);
        int t=sum(x[i]+1)-1;
        res[t]++;
    }
    for(i=0;i<n;i++)
        printf("%d\n",res[i]);
    return 0;
}
