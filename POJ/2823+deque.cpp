/*
��������(deque)
ά����Сֵqmin�У������ҵ�������
ά�����ֵqmax�У������ҵ����ݼ�
*/
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn=1000000+5;
int a[maxn],b[maxn],c[maxn];

/*
���ڴ��ڵĻ�����ÿ��Ҫ��Ҫ�ж϶����������(������ͷ��)��Ԫ���Ƿ�
����Ϊ��������ɾ������ô���Ǳ���Ҫ֪�������Ԫ����ԭ�����е�λ��
(���±�),����������deque�����б����ÿ��Ԫ�ص��±꣬����Ԫ�ص�ֵ
*/

int deq1[maxn*2],deq2[maxn*2];

//�򵥵����������Ԫ��ʱ�������䵥���Զ��֣������Ų���ʱ
int B_search1(int s,int t,int x){
    int l=s,r=t;
    while(l<r){
        int m=(l+r)/2;
        if(a[deq1[m]]>=x)
            r=m;
        else
            l=m+1;
    }
    return r;
}

int B_search2(int s,int t,int x){
    int l=s,r=t;
    while(l<r){
        int m=(l+r)/2;
        if(a[deq2[m]]>x)
            l=m+1;
        else
            r=m;
    }
    return r;
}

int main()
{
    int i,j,k,n,s1,t1,s2,t2;
    scanf("%d%d",&n,&k);
 //   for(i=0;i<n;i++)

    s1=t1=s2=t2=0;
    int f=0;
    for(i=0;i<n;i++){
      //  while(s1<t1 && a[deq1[t1-1]]>=a[i])      //ע�⣺��������ÿ�εıȽϲ����ǴӺ���ǰ��
      //      t1--;
        scanf("%d",&a[i]);
        if(s1<t1)
            t1=B_search1(s1,t1,a[i]);
        deq1[t1++]=i;
        if(i-k+1>=0){       //���i<k,��˵�����ڴ����л�����k������Ҫ������ӣ����˵Ļ���ִ�и�if
          //  b[i-k+1]=a[deq1[s1]];
            if(f)
                printf(" ");
            f++;
            printf("%d",a[deq1[s1]]);
            if(deq1[s1]==i-k+1)           //ǡ����Ϊ���ڵĻ�����ɾ������ͷ����Ԫ��
                s1++;
        }
  //      while(s2<t2 && a[deq2[t2-1]]<=a[i])
   //         t2--;

    }
    printf("\n");
    f=0;
    for(i=0;i<n;i++){
            if(s2<t2)
            t2=B_search2(s2,t2,a[i]);
        deq2[t2++]=i;
        if(i-k+1>=0){
            if(f)
                printf(" ");
            f++;
            printf("%d",a[deq2[s2]]);
            if(deq2[s2]==i-k+1)
                s2++;
        }
    }
    printf("\n");
    return 0;
}
