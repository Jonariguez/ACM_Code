/*
由两个操作的特点可以看的出，被套进的那个
必须是单独的，所以我们要从1开始一个一个
往后套(保证后面的是单个的)
即 1->2   12->3  123->4  1234->5 ....
只要1从开头一直连续的不用断开，其他的都要
断开个单个的，然后再重组
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
int a[maxn];

int main()
{
    int i,j,k,n,m,res;
    while(scanf("%d%d",&n,&k)!=EOF){
        res=0;
        int x;
        for(i=0;i<k;i++){
            scanf("%d",&m);
            for(j=0;j<m;j++) scanf("%d",&a[j]);
            if(a[0]!=1){
                res+=m-1;continue;
            }
            for(j=0;j<m;j++)
                if(a[j]!=j+1) break;
            res+=m-j;
        }
        printf("%d\n",res*2+k-1);
    }
    return 0;
}
