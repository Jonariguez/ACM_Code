/*
hash
很明显，在前面的处理，vis存的数是[1,nc],
我们要的是nc进制的数，即[0,nc-1],计算的
时候我们就减1，vis[str[j]]-1
不减也行~
*/
#include <stdio.h>
#include <string.h>

const int maxn=16000000+10;
char str[maxn];
bool hash[maxn];
int vis[10000];

int main()
{
    int i,j,n,nc,len;
    scanf("%d%d%s",&n,&nc,str);
    int cnt=0;
    len=strlen(str);
    for(i=0;i<len;i++){
        if(vis[str[i]]==0)
            vis[str[i]]=++cnt;
        if(cnt==nc) break;      //因为一共最多只有nc钟字符，如果已经为nc种字符
    }                           //编号了(在vis里)，那么以后就肯定没有新字符出现了
    int sum=0,res=0;
    for(i=0;i+n-1<len;i++){
        sum=0;
        for(j=i;j<i+n;j++)              //vis里也就相当于把每个字符转换为nc进制中数，然后将
            sum=sum*nc+vis[str[j]]-1;     //n长度的子串转化为一个nc进制的整数来hash
        if(hash[sum]==0){
            res++;hash[sum]=1;
        }
    }
    printf("%d\n",res);
    return 0;
}
