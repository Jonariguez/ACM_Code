#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int fac[10],cnt[10];

int f(int d,int n){
    char s[10];
    sprintf(s,"%d",n);
    int len=strlen(s),ans=0,i;

    for(i=1;i<len;i++){     //����[1,len-1]λ����ʱ��
        if(i==1) ans++;
        else {
            ans+=9*cnt[i-1];
            if(d>0)
                ans+=fac[i-1];
        }
    }

    int pre[10];
    for(i=0;i<len;i++){
        pre[i]=(s[i]-'0'==d?1:0);
        if(i) pre[i]+=pre[i-1];     //����ǰ����ֹ�����d
    }

    for(i=0;i<len;i++){
        int maxv=s[i]-'0';
        int minv=0;
        if(i==0 && len>1) minv=1;
        for(int digit=minv;digit<maxv;digit++){     //����ÿһλ��ö��[0,s[i]-1](��һλ����[1,s[i]-1]
            ans+=cnt[len-i-1];                  //����len-i-1��һ����cnt[len-i-1]��d
            if(digit==d)
                ans+=fac[len-i-1];              //�����d��ͷ������10^(len-i-1)�ĵ�
            if(i) ans+=pre[i-1]*fac[len-i-1];   //ע��������ѭ����s[i]-1,���ڴ���s[i],����s[i]��û�д�d��
        }                                       //���˾��㣬�����Ϳ϶�û��d.    ���һ�¡�
    }
    return ans;
}

int main()
{
    int i,a,b;
    fac[0]=1;
    for(i=1;i<10;i++){
        fac[i]=fac[i-1]*10;
        cnt[i]=fac[i-1]*i;
    }
    while(scanf("%d%d",&a,&b)){
        if(a==0 && b==0) break;
        if(a>b) swap(a,b);
        for(i=0;i<10;i++){
            if(i) printf(" ");
            printf("%d",f(i,b+1)-f(i,a));
        }
        printf("\n");
    }
    return 0;
}
