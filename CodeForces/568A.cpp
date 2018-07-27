/****************
*PID:568A div1
*Auth:Jonariguez
*****************
暴力，一开始用1e6没过，题解是2e6
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef __int64 LL;

const int maxn=10000000;
int p[maxn+10],rub[maxn+10];
bool vis[maxn+10];

void get_table(){
    int i,j;
    vis[1]=1;
    for(i=2;i*i<=maxn;i++){
        if(!vis[i]){
            for(j=i*i;j<=maxn;j+=i)
                vis[j]=1;
        }
    }
}

int check(int n){
    int bit[11],i,tot=0;
    while(n){
        bit[tot++]=n%10;
        n/=10;
    }
    for(i=0;i<tot/2;i++)
        if(bit[i]!=bit[tot-i-1]) return 0;
    return 1;
}

void pre_solve(){
    int i,cntp=0,cntr=0;
    p[0]=rub[0]=0;
    for(i=1;i<=maxn;i++){
        p[i]=p[i-1]+(!vis[i]);
        rub[i]=rub[i-1]+check(i);
    }
}


int main()
{
    int i,j,n,P,Q;
    get_table();
    pre_solve();
    while(scanf("%d%d",&P,&Q)!=EOF){
        for(n=maxn;n>=1;n--)
            if((LL)Q*p[n]<=(LL)P*rub[n]) break;
        if(n==0)
            printf("Palindromic tree is better than splay tree\n");
        else printf("%d\n",n);
    }
    return 0;
}
