#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int fac[10],cnt[10];

int f(int d,int n){
    char s[10];
    sprintf(s,"%d",n);
    int len=strlen(s),ans=0,i;

    for(i=1;i<len;i++){     //处理[1,len-1]位数的时候
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
        if(i) pre[i]+=pre[i-1];     //保存前面出现过几次d
    }

    for(i=0;i<len;i++){
        int maxv=s[i]-'0';
        int minv=0;
        if(i==0 && len>1) minv=1;
        for(int digit=minv;digit<maxv;digit++){     //对于每一位，枚举[0,s[i]-1](第一位的是[1,s[i]-1]
            ans+=cnt[len-i-1];                  //后面len-i-1后一共有cnt[len-i-1]个d
            if(digit==d)
                ans+=fac[len-i-1];              //如果以d开头，则共有10^(len-i-1)的的
            if(i) ans+=pre[i-1]*fac[len-i-1];   //注意上面是循环到s[i]-1,现在处理s[i],看“s[i]有没有大到d”
        }                                       //到了就算，不到就肯定没有d.    体会一下。
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
