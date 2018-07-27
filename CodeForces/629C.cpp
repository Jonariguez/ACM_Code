/****************
*PID:629c div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=4010+5;
const LL mod=1e9+7;
LL C[maxn][maxn];
char str[100005];

void Ctable(){
    LL i,j;
    for(i=0;i<=4014;i++){
        for(j=0;j<=4014;j++){
            if(j==0 || j==i) C[i][j]=1;
            else if(j<=i)
                C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
            else if(j>i) C[i][j]=0;
        }
    }
}

int main()
{
    LL i,j,n,m;
    Ctable();
    while(scanf("%I64d%I64d",&n,&m)!=EOF){
        scanf("%s",str+1);
        if(n&1){
            puts("0");continue;
        }
        LL left=0,right=0,d=0;
        for(i=1;i<=m;i++){
            if(str[i]=='(') left++;
            else right++;
            d=max(d,right-left);
        }
        LL res=0;
        for(i=0;i<=(n/2-right) && i<=n-m;i++){    //枚举p中右括号的个数
            for(j=i+d;j<=(n/2-left) && i+j<=n-m;j++){
                LL L=n/2-j-left,R=n/2-i-right;
                res+=((C[i+j][i]-C[i+j][j+1])*(C[L+R][L]-C[L+R][R+1])%mod);
                res%=mod;
            }
        }
        if(res<0) res+=mod;
        printf("%I64d\n",res%mod);
    }
    return 0;
}
