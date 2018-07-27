#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=10000+10;
int p[maxn],tot;
bool is[maxn];

void prime_table(){
    int i,j;
    tot=0;
    memset(is,0,sizeof(is));
    for(i=2;i<=10000;i++){
        if(!is[i]){
            p[tot++]=i;
            for(j=i*2;j<=10000;j+=i)
                is[j]=1;
        }
    }
}

int main()
{
    int i,j,s,t,n,res,sum;
    prime_table();
    while(scanf("%d",&n),n){
        s=t=res=sum=0;
        for(;;){
            while(t<tot && sum<n)
                sum+=p[t++];
            if(sum<n) break;
            if(sum==n) res++;
            sum-=p[s++];
        }
        printf("%d\n",res);
    }
    return 0;
}
