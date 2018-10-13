/****************
*PID:bzoj1009
*Auth:Jonariguez
*****************
dp[i][j]:����iλ�����ҳ���Ϊj�ĺ�׺ƥ����ǰjΪ���������֡�
������dp[i][j]ֻ����dp[i-1][k]����,
dp[i-1][k]��ת�Ƶ�dp[i][j]�����ڵ�iλ����ĳ�����ֺ���Ĳ�����
��׺������k�����j��
(ע�⣬j������Ǹ�������121124����dp[5][2]׷���ˡ�1��֮��ת�Ƶ�dp[6][1],
 ����ת�Ƶ�dp[6][3],��Ϊ��Ĳ�������׺�ǳ���Ϊ3�ġ�121���������ǡ�1��)
Ȼ����Ա����ҵ�ת�Ʒ�ʽ����kmpҲ�С�
��Ϊdp[i][j]ֻ����dp[i-1][]����,��ת��Ϊ���ԣ��ʿ��þ�������������١�
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("d",&x,&y)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#define MP make_pair
#define X first
#define Y second
#define PI acos(-1.0)
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=200000+10;
const int MOD=1e9+7;

int N,M,K;
char str[22],now[22];

struct Mat{
    int mat[22][22];
    Mat(){
        memset(mat,0,sizeof(mat));
    }
    void EMat(){
        for(int i=0;i<=20;i++)
            mat[i][i]=1;
    }
}ori;

Mat multi(Mat a,Mat b){
    Mat res;
    memset(res.mat,0,sizeof(res.mat));
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<M;k++){
                res.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
                res.mat[i][j]%=K;
            }
        }
    }

    return res;
}

Mat Pow(Mat a,int n){
    Mat res;
    res.EMat();
    while(n){
        if(n&1)
            res=multi(res,a);
        n/=2;
        a=multi(a,a);
    }
    return res;
}

int yes;

void solve(int n){
    for(int len=n-1;len>=1;len--){  //len��n-1��ʼ����Ϊ������Ĳ�������׺��
        int st1=1,st2=n-len+1;
        while(st1<=len && st2<=n){
            if(now[st1]!=now[st2]) break;
            st1++;st2++;
        }
        if(st1>len){
            ori.mat[len][n-1]++;yes++;break;    //�ҵ���break����
        }
    }
}

int dp[2][21];

int main()
{
    int i,j,k;
    scanf("%d%d%d",&N,&M,&K);
    scanf("%s",str+1);
    for(i=1;i<=M;i++){
        for(j=1;j<i;j++) now[j]=str[j];
        yes=0;
        for(j=0;j<=9;j++){
            if(str[i]==('0'+j)){
                ori.mat[i][i-1]++;yes++;continue;
            }
            now[i]=('0'+j);
            solve(i);
        }
        //����ͨ���ֱ����0~9���֣���һ����������׺ת�Ƶ���һ����0���ȵĲ�������׺��ʣ��
        //10-yes��ֻ��ת�Ƶ�0����û�в������ĺ�׺��
        ori.mat[0][i-1]=10-yes;
    }

    Mat ans=Pow(ori,N-1);
    //��ʼֵ
    dp[1][0]=9;
    dp[1][1]=1;
    int res=0;
    for(i=0;i<M;i++){
        for(j=0;j<M;j++){
            res+=ans.mat[i][j]*dp[1][j];
            res%=K;
        }
    }
    printf("%d\n",res);
    return 0;
}




