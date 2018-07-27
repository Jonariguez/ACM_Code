/****************
*ID:uva766
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

LL c[23][23],M[23],A[23][23];

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

LL Abs(LL v){
    return v<0?-v:v;
}

void pre_solve(){
    int i,j,k;
    memset(c,0,sizeof(c));
    memset(A,0,sizeof(A));
    memset(M,0,sizeof(M));
    for(i=0;i<=22;i++){
        for(j=0;j<=i;j++)
            if(j==0 || j==i)
                c[i][j]=1;
            else c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    M[0]=1;A[0][1]=1;
    for(i=1;i<=20;i++){
        M[i]=i+1;
        LL lcm_M=1;
        for(j=0;j<i;j++)        //������M[i]ͨ�֣�����С������lcm_M,��ĸ�����С������
            lcm_M = lcm_M/gcd(lcm_M,M[j]) * M[j];
        M[i]*=lcm_M;
        for(j=0;j<i;j++)        //S(k,n)�ṱ��k+1���[0,j+1]
            for(k=0;k<=j+1;k++)     //��ô���Ӿ���Ӧ�ĳ�����С��������Ȼ���ٳ�ȥ��������*lcm_M/M[j]
                A[i][k]-=A[j][k]*lcm_M/M[j]*c[i+1][j];  //�����A[i][k]��ʾS(i,n)��ϵ��a^k
   //     A[i][i+1]=1
        for(j=1;j<=i+1;j++)         //������Ϊǰ�滹�и�(n+1)^(k+1)����Ϊ����Ҫ����n^(k+1)������Ҫ�����չ������
            A[i][j]+=lcm_M*c[i+1][j]; //����ϲ���ע��j��1��ʼ����Ϊ(n+1)^(k+1)չ��û�г�����ϵ�������Բ�Ӱ����
        LL g=M[i];          //����������M��ai����С��Լ������Լ�ֵ�
        for(j=0;j<=i+1;j++)
            g=gcd(g,Abs(A[i][j]));
        M[i]/=g;
        for(j=0;j<=i+1;j++)
            A[i][j]/=g;
    }
}

int main()
{
    int i,k,T;
    pre_solve();
    scanf("%d",&T);
    while(T--){
        scanf("%d",&k);
        printf("%lld",M[k]);
        for(i=k+1;i>=0;i--)
            printf(" %lld",A[k][i]);
        printf("\n");
        if(T)
            puts("");
    }
    return 0;
}
