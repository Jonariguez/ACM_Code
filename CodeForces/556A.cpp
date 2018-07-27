/*
只要同时存在0和1就一定能消除
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=200000+10;
char str[maxn];

int main()
{
    int i,zero,one,n;
    while(scanf("%d",&n)!=EOF){
        scanf("%s",str);
        zero=one=0;
        for(i=0;i<n;i++)
            if(str[i]=='0') zero++;
            else one++;
        printf("%d\n",max(zero,one)-min(zero,one));
    }
    return 0;
}
