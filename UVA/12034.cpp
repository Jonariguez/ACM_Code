/*
���Ϊf(n),�����һ����i���ˣ���C(n,i)�ֿ��ܣ�������
��f(n-i)�ֿ��ܣ����Դ�Ϊ��sigma{C(n,i)*f(n-i)}
��Ϊ���Ҫ��10056ȥģ�����������Ҫͨ�����ķ�ʽ�õ���
��Ϊ���ʱֻҪ�ӷ���ȡģ�Դ��û��Ӱ�졣�����
C(n,k)=(n-k+1)/k*C(n,k-1)ֱ�ӵ��Ƶó������ܱ�֤����ȷ��
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

