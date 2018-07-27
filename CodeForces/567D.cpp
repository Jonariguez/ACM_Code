/****************
*PID:567D div2
*Auth:Jonariguez
*****************
二分
注意一个长度为len的cells，放长度为a的ship的个数为(len+1)/(a+1)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=200000+10;
int n,k,a;
int s[maxn],t[maxn];

bool C(int m){
    int i,cnt=0;
    for(i=1;i<=m;i++)
        t[i]=s[i];
    sort(t+1,t+m+1);
    int last=1;
    for(i=1;i<=m;i++){
        cnt+=(t[i]-last+1)/(a+1);
        last=t[i]+1;
    }
    cnt+=(n-last+2)/(a+1);
    return cnt>=k;
}


int main()
{
    int i,j;
    while(scanf("%d%d%d",&n,&k,&a)!=EOF){
        int m;
        scanf("%d",&m);
        for(i=1;i<=m;i++)
            scanf("%d",&s[i]);
        int l=1,r=m,res=maxn;
        while(l<=r){
            int M=(l+r)/2;
            if(C(M))
                l=M+1;
            else {
                r=M-1;res=min(res,M);
            }
        }
        if(res==maxn)
            printf("-1\n");
        else printf("%d\n",res);
    }
    return 0;
}
