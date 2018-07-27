/*
尺取法
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
typedef __int64 ll;

const int maxn=10000000+5;
ll a[maxn];
struct pp
{
    ll start,L;
}S[maxn];

int cmp(const pp &x,const pp &y){
    if(x.L==y.L) return x.start<y.start;
    return x.L>y.L;
}

void pre_solve(){
    ll i;
    for(i=1;i<=10000000;i++)
        a[i]=i*i;
}

int main()
{
    ll i,j,n,s,t,sum,res;
//    pre_solve(); //注意，因为特殊性，尺取的数组可以由下标直接确定（a[i]=i*i),所以下面可以用i*i代替a[i]，不然打表会TLE
    while(scanf("%I64d",&n)!=EOF){
        s=t=1;sum=0;
        ll cnt=0;
        for(;;){
            while(t*t<=n && sum<n){
                sum+=t*t;t++;
            }
            if(sum<n) break;
            if(sum==n){
                S[cnt].L=t-s;
                S[cnt++].start=s;
            }
            sum-=s*s;
            s++;
        }
        if(cnt==0){
            printf("0\n");
            continue;
        }
        sort(S,S+cnt,cmp);
        printf("%I64d\n",cnt);
        for(i=0;i<cnt;i++){
            printf("%I64d",S[i].L);
            for(j=S[i].start;j<S[i].start+S[i].L;j++)
                printf(" %I64d",j);
            printf("\n");
        }
    }
    return 0;
}
