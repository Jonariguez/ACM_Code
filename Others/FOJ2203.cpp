/****************
*PID:foj2203
*Auth:Jonariguez
*****************
¶þ·Ö
*/
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;

const int maxn=200000+10;
int b[maxn],s[maxn];
int n,k,a;

bool C(int m){
    int i;
    for(i=1;i<=m;i++)
        s[i]=b[i];
    sort(s+1,s+m+1);
    int cnt=0,last=1;
    for(i=1;i<=m;i++){
        cnt+=(s[i]-last+1)/(a+1);
        last=s[i]+1;
    }
    cnt+=(n-last+2)/(a+1);
    return cnt>=k;
}

int main()
{
    int i,j,res;
    while(scanf("%d%d%d",&n,&k,&a)!=EOF){
        int m;
        scanf("%d",&m);
        for(i=1;i<=m;i++)
            scanf("%d",&b[i]);
        int l=1,r=m;
        res=maxn;
        while(l<=r){
            int M=(l+r)/2;
            if(C(M))
                l=M+1;
            else {
                r=M-1;res=min(res,M);
            }
        }
        if(res==maxn) res=-1;
        printf("%d\n",res);
    }
    return 0;
}
