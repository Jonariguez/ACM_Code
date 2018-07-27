/*
ֱ��ģ�⣬��������ÿ��ȷ��һ������һ���ҵ�[cnt,n](cnt��ʼΪ1)�б����
����Ǹ�������±�(index),Ȼ��ת"index",������������Ȼ��ͨ����ת"cnt",
����������ײ�������λ��ȷ����cnt++���ڶ�����[cnt,n]������ֵ��Ȼ��
��תindex��cnt���������ƣ�ֱ��ȫ��ȷ��
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=33;
int a[maxn],n;

bool check(int s,int &index){   //�жϴ�s��ʼ���ϵ����Ƿ������ҳ�������ļ�����±�
    int i,ok=1,maxv=a[s];
    index=s;
    for(i=s+1;i<=n;i++){
        if(maxv<a[i]){
            maxv=a[i];index=i;
        }
        if(a[i]>a[i-1])
            ok=0;
    }
    return ok==1;
}

void flip(int s){       //��[s,n]���䷭ת
    for(int i=s;i<=(s+n)/2;i++){
        int t=a[i];
        a[i]=a[n-i+s];a[n-i+s]=t;
    }
}

int main()
{
    int i,j,m,x;
    char c;
    while(scanf("%d",&a[1])!=EOF){
        scanf("%c",&c);
        if(c=='\n'){
            printf("%d\n0\n",a[1]);continue;    //���˴���һ�����������wa��һ��
        }
        n=1;
        while(scanf("%d%c",&x,&c)){
            a[++n]=x;
            if(c=='\n') break;
        }
        for(i=1;i<=n;i++)
            printf("%d%c",a[i],i==n?'\n':' ');
        for(i=1;i<=n/2;i++){
            int t=a[i];
            a[i]=a[n-i+1];a[n-i+1]=t;
        }
        int cnt=0,index;
        while(cnt++!=n){
            if(cnt==n || check(cnt,index)){ //���ֻʣ���һ�����������ȫ�����������ٷ���
                printf("0\n");break;
            }
            if(index==cnt){     //���index���ڵ�ǰλ�ã��Ͳ��÷�������ȷ����һ�����������
                continue;
            }
            if(index!=n){       //���������棬�Ͱ�������������
                printf("%d ",index);
                flip(index);
            }
            printf("%d ",cnt);  //Ȼ�󷭵�cntλ��
            flip(cnt);
        }
    }
    return 0;
}
