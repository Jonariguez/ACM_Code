/****************
*ID:hdu3579
*Auth:Jonariguez
*****************
同余方程组
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=11;
int M[maxn],A[maxn];
ll lcm;

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

void Ex_gcd(int a,int b,int &d,int &x,int &y){
    if(b==0){
        x=1;y=0;d=a;return ;
    }
    Ex_gcd(b,a%b,d,y,x);
    y-=(a/b)*x;
}

ll solve(int n){
    int i,j,a1,a2,r1,r2,a,b,c,d,x,y;
    bool yes=true;
    a1=M[0];r1=A[0];
    for(i=1;i<n;i++){
        a2=M[i];r2=A[i];
        a=a1;b=a2;c=r2-r1;      //a1,a2是除数，r1，r2是余数
        Ex_gcd(a,b,d,x,y);
        if(c%d)
            yes=false;
        int t=b/d;
        x=(x*(c/d)%t+t)%t;
        r1+=a*x;
        a1=a1/d*b;
    }
    if(!yes)
        r1=-1;
    return r1;
}

int main()
{
    int i,j,n,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        lcm=1;
        for(i=0;i<n;i++){
            scanf("%d",&M[i]);
            lcm=lcm/gcd(lcm,M[i])*M[i];
        }
        for(i=0;i<n;i++)
            scanf("%d",&A[i]);
        ll res=solve(n);
        if(res==0)
            res=lcm;
        printf("Case %d: %lld\n",kcase++,res);
    }
    return 0;
}
