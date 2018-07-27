/****************
*PID:hdu5505
*Auth:Jonariguez
*****************
数论
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;
typedef __int64 LL;

const int maxn=1000000+10;
const int INF=100000;
vector<int> prime;
bool vis[maxn];
int e[maxn],cot[maxn];      //e保存n分解后的素因子，cot是对应的指数

void table(){
    int i,j;
    for(i=2;i<=1000000;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(j=i*2;j<=1000000;j+=i)
                vis[j]=1;
        }
    }
}

int div(int n,int *a,int *b){
    int tot=0,i,cnt=0;
    for(i=0;i<prime.size() && (LL)prime[i]*prime[i]<=(LL)n;i++){
        int x=prime[i];
        if(n%x==0){
            cnt=0;
            while(n%x==0){
                cnt++;
                n/=x;
            }
            a[tot]=x;b[tot++]=cnt;
        }
    }
    if(n!=1){
        a[tot]=n;b[tot++]=1;
    }
    return tot;
}

int solve(ULL m,int tot){
    int i,res=-1,cnt=0,cnt1,p,t;
    ULL x;
    for(i=0;i<tot;i++){
        if(m%e[i]!=0) return -1;    //如果n中有的素因子，而m中没有则-1
        p=e[i];
        cnt=0;
        while(m%p==0){
            cnt++;m/=p;
        }
        t=cot[i];cnt1=0;
        if(cnt<t) return -1;        //如果某个素因子在m中的次数比在n中的高，则-1
        while(t<cnt){
            cnt1++;t*=2;            //成倍增长得最少次数
        }
        res=max(res,cnt1);          //res更新保存每个次数的最大值，这里我一开始是取的min，一直WA.......
    }
    if(m!=1) return -1;         //如果m中有的素因子，而n中没有则-1
    return res;
}

int main()
{
    int i,j,T;
    int n;
    ULL m;
    table();
    scanf("%d",&T);
    while(T--){
        scanf("%d%llu",&n,&m);
        if(n==m){
            printf("0\n");
            continue;
        }
        if((n==1 && m!=1) || n>m){
            printf("-1\n");continue;
        }

        int tot=div(n,e,cot);
        printf("%d\n",solve(m,tot));
    }
    return 0;
}

