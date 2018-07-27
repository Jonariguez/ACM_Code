#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=30000000;
int sum[maxn+5];

void solve(){
    int a,b,c;
    for(c=1;c<=maxn;c++){
        for(a=c*2;a<=maxn;a+=c){
            b=a-c;
            if((a^b)==c) sum[a]++;
        }
    }
    sum[0]=0;
    for(int i=1;i<=maxn;i++)
        sum[i]+=sum[i-1];
}


int main()
{
    int i,T,n,kcase=1;
    solve();
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("Case %d: %d\n",kcase++,sum[n]);
    }
    return 0;
}
