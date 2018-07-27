/****************
*PID:559C div1
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef __int64 LL;

const LL MOD=1000000007;

LL fact[200005],inv[200005];
LL dp[10005];
LL h,w,n;

struct Point{
    int x,y;
    bool operator < (const Point &r) const {
        if(x!=r.x) return x<r.x;
        return y<r.y;
    }
}s[10005];

void Exgcd(LL a,LL b,LL &d,LL &x,LL &y){
    if(b==0){
        d=a;x=1;y=0;return ;
    }
    Exgcd(b,a%b,d,y,x);
    y-=(a/b)*x;
}

LL Inv(LL a,LL n){
    LL d,x,y;
    Exgcd(a,n,d,x,y);
    return d==1?(x+n)%n:-1;
}

LL Comb(LL n,LL m){
    LL res=fact[n];
    res=(res*inv[m])%MOD;
    res=(res*inv[n-m])%MOD;
    return res;
}

void Init(){
    fact[0]=fact[1]=inv[0]=inv[1]=1;
    for(int i=2;i<=200000;i++){
        fact[i]=(fact[i-1]*i)%MOD;
        inv[i]=Inv(fact[i],MOD);
    }
}

int main()
{
    int i;
    Init();
    while(scanf("%I64d%I64d%I64d",&h,&w,&n)!=EOF){
        for(i=0;i<n;i++)
            scanf("%d%d",&s[i].x,&s[i].y);
        sort(s,s+n);
        LL res=Comb(h+w-2,h-1);
        for(i=0;i<n;i++){
            dp[i]=Comb(s[i].x+s[i].y-2,s[i].x-1);
            for(int j=0;j<i;j++){
                if(s[j].x<=s[i].x && s[j].y<=s[i].y){
                    dp[i]=(dp[i]-dp[j]*Comb(s[i].x-s[j].x+s[i].y-s[j].y,s[i].x-s[j].x))%MOD;
                }
            }
            res=(res-dp[i]*Comb(h-s[i].x+w-s[i].y,h-s[i].x))%MOD;
        }
        res=(res+MOD)%MOD;
        printf("%I64d\n",res%MOD);
    }
    return 0;
}
