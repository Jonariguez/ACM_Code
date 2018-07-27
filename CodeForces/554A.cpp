/*
除了把26个字母每次选一个
放在最前面能形成26个不同的，
那么以后在后面的位置放的时候
不能和前一个位置相同，每个位置
共25中情况
*/
#include <stdio.h>
#include <string.h>

int main()
{
    int i,n;
    char s[22];
    while(scanf("%s",s)!=EOF){
        n=strlen(s);
        printf("%d\n",n*25+26);
    }
    return 0;
}
