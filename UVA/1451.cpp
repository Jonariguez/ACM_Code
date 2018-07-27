/*
���ν��
һ��ʼŪ���ˣ������еĵ㶼Ԥ�����ˣ������ó���͹��Ȼ��
������ǲ��Ե�(��Ϊ��ѡȡ�������Ҷ˵�ʱ����ô�ö˵����
�ĵ��Ƕ���û��Ӱ��ģ����ԾͿ�������������)��Ҫ�ߴ���
����⡣
���㷨����С����ö��t�������ҵ�t'<=t-l,ʹ��[t',t]б�����
��Ϊ������СΪl,����tӦ�ô�l�ӿ�ʼö�ٵ�n����ôt'�ķ�Χ����
[1,t-l]������ÿ��ö��һ��tʱ����ô��Ӧ�ð�t-l��ӵ��C��
(��"����C"),��ô����t-l֮ǰ��Ҫά����͹�ߡ�ά������͹��
֮��ֱ�������������˵�(ö�ٵ�t�����Ҷ˵�).
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
char str[maxn];
int s[maxn],sum[maxn],stack[maxn],n,l;

//�Ƚ�����[x1,y1]��[x2,y2]�Ľ����С
int cmp(int x1,int y1,int x2,int y2){
    return ((ll)sum[y1]-sum[x1-1])*(y2-x2+1)-((ll)sum[y2]-sum[x2-1])*(y1-x1+1);
}

int main()
{
    int i,T,j,head,tail,t;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&l);
        scanf("%s",str+1);
        sum[0]=0;
        for(i=1;i<=n;i++)
            sum[i]=sum[i-1]+(str[i]-'0');
        int ansL=1,ansR=l;
        head=tail=0;
        for(t=l;t<=n;t++){
            //tail-head>1�Ǳ�֤stack�������������㣬�����һ������
            //ֱ�Ӽ���㼴�ɣ�һ�����㡣  "����C"
            //��ʵÿ��cmpʱ��stack�е����һ����ʵ��t-l�����Ⲣ��Ӱ��
            //cmp�����������Ӱ��ά����͹�ߡ�֮�����Ѿ���t-l����Ϊ�ϴ�
            //ѭ��ʱ��stack[tail++]=t-l+1��
            while(tail-head>1 && cmp(stack[tail-2],t-l,stack[tail-1],t-l)>=0)
                tail--;
            stack[tail++]=t-l+1;

            while(tail-head>1 && cmp(stack[head],t,stack[head+1],t)<=0)
                head++;
            int c=cmp(stack[head],t,ansL,ansR);
            if(c>0 || c==0 && t-stack[head]<ansR-ansL){
                ansL=stack[head];ansR=t;
            }
        }
        printf("%d %d\n",ansL,ansR);
    }
    return 0;
}
