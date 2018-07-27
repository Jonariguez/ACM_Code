/*
n是奇数
如果去掉两个不同的元素，那么原序列的
多元素在新序列中仍然是多元素。
我们用res记录数，cnt记录和res相等的个数，
即遇到和res相等的cnt++，不等cnt--。
cnt=0时为res重新复制。 最后res就是答案
*/
#include <stdio.h>
#include <string.h>

int main()
{
    int i,n,res,cnt,x;
    while(scanf("%d",&n)!=EOF){
        cnt=0;
        for(i=0;i<n;i++){
            scanf("%d",&x);
            if(cnt==0){
                res=x;cnt++;
            }else if(res==x)
                cnt++;
            else if(res!=x) cnt--;
        }
        printf("%d\n",res);
    }
    return 0;
}
