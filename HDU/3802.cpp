/****************
*PID:hdu3802
*Auth:Jonariguez
*****************
http://blog.csdn.net/magicnumber/article/details/6280257
学习上面关于欧拉值的那个公式及应用前提。
http://blog.csdn.net/aozil_yang/article/details/50596293
学习上面博客的那张图，有比较详细的计算。
为什么要选择x1,y1,看下面博客：
http://www.cnblogs.com/zjh10/articles/2035938.html
这句话：实际上两项一起的时候达到相除根号的目的，而这个时候应该想办法通项公式求递推式。。。
相当于以前求特征方程然后求通项的逆运算 - -
然后对于z=c1*x^n+c2*y^n ，你要构造以x，y为解的一元二次方程...然后把这个特征方程(x^2=px+q)转
成递归式(Zn=p*Zn-1+q*Zn-2)就可以了

下面博客有不套公式，直接推导出递推式的：
http://blog.csdn.net/shiyuankongbu/article/details/9408503
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
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
typedef long long Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;
LL MOD;

struct Mat{
    LL mat[3][3];
    Mat(){
        memset(mat,0,sizeof(mat));
    }
    void EMat(){
        mat[1][1]=mat[2][2]=1;
    }
};

Mat Multi(Mat a,Mat b){
    Mat c;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            for(int k=1;k<=2;k++){
                c.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
                c.mat[i][j]%=MOD;
            }
        }
    }
    return c;
}

Mat quick_Pow(Mat a,LL n){
    Mat res;
    res.EMat();
    while(n){
        if(n&1)
            res=Multi(res,a);
        n/=2;
        a=Multi(a,a);
    }
    return res;
}
/* |1 1| * |fn-1| = |fn  |
** |1 0|   |fn-2|   |fn-1|
*/
LL Fib(LL n){   //求Fib数列
    if(n<=1) return 1%MOD;
    if(n==2) return 2%MOD;
    Mat trans;
    trans.mat[1][1]=1%MOD;trans.mat[1][2]=1%MOD;
    trans.mat[2][1]=1%MOD;trans.mat[2][2]=0;
    Mat res=quick_Pow(trans,n-1);
    return (res.mat[1][1]+res.mat[1][2])%MOD;
}

LL solve_hard(LL a,LL b,LL fib){
    if(fib==0) return 2%MOD;
    if(fib==1) return 2*(a+b)%MOD;
    Mat trans;
    trans.mat[1][1]=2*(a+b)%MOD;trans.mat[1][2]=-(a-b)*(a-b)%MOD;
    trans.mat[2][1]=1%MOD;trans.mat[2][2]=0;
    Mat res=quick_Pow(trans,fib-1);
    return (res.mat[1][1]*2*(a+b)%MOD+res.mat[1][2]*2%MOD)%MOD;
}

int main()
{
    int i,j,T;
    sc(T);
    while(T--){
        LL a,b,n;
        scanf("%I64d%I64d%I64d%I64d",&a,&b,&n,&MOD);
        LL ta=(quick_pow(a,(MOD-1)/2,MOD)+1)%MOD;
        LL tb=(quick_pow(b,(MOD-1)/2,MOD)+1)%MOD;
        if(ta==0 || tb==0){
            puts("0");continue;
        }
        MOD--;
        LL fib=Fib(n);
        MOD++;
        LL res=solve_hard(a,b,fib);
        res=ta*tb%MOD*res%MOD;
        if(res<0) res+=MOD;
        printf("%I64d\n",res);
    }
    return 0;
}



