/*
设答案为f(n),假设第一名有i个人，有C(n,i)种可能，接下来
有f(n-i)种可能，所以答案为：sigma{C(n,i)*f(n-i)}
因为结果要对10056去模，所有组合数要通过打表的方式得到，
因为打表时只要加法，取模对打表没有影响。如果由
C(n,k)=(n-k+1)/k*C(n,k-1)直接递推得出，则不能保证答案正确。
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
typedef long long ll;

const int MOD=10056;
unsigned short c[1002][1002];

void get_com(){
    ll i,j;
    for(i=0;i<=1000;i++){
        for(j=0;j<=i;j++){
            if(j==0 || j==i)
                c[i][j]=1;
            else c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
        }
    }
}

ll f[1010];

//C(n,k)=(n-k+1)/k*C(n,k-1)
void solve(){
    ll i,j;
    get_com();
    f[0]=1;f[1]=1;f[2]=3;
    for(i=3;i<=1000;i++){
        f[i]=0;
        for(j=1;j<=i;j++){
            f[i]+=c[i][j]*f[i-j];
            f[i]%=MOD;
        }
    }
}

int main()
{
    int n,T,kcase=1;
    solve();
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("Case %d: %lld\n",kcase++,f[n]%MOD);
    }
    return 0;
}

