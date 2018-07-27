/*
也就是说，对于某个字符串S，长度为N，由长度为n的
字符串s重复R次得到，当R≥2时必然有S[1..N-n]=S[n+1..N]。
那么对于KMP算法来说，就有fail[N]=N-n。此时n肯定已经
是最小的了。
然后只需要判断N是否n的倍数，是则输出N/n即可。否则输出1。
*/
#include <stdio.h>
#include <string.h>

const int maxn=1000000+10;
char str[maxn];
int next[maxn];

void get_next(){
    int i,j,n;
    n=strlen(str);
    next[0]=next[1]=j=0;
    for(i=1;i<n;i++){
        while(j && str[j]!=str[i])
            j=next[j];
        if(str[j]==str[i]) j++;
        next[i+1]=j;
    }
}

int main()
{
    int i,j,n;
    while(scanf("%s",str)){
        if(str[0]=='.') break;
        get_next();
        n=strlen(str);
        if(n%(n-next[n])==0)
            printf("%d\n",n/(n-next[n]));
        else printf("1\n");
    }
    return 0;
}
