/****************
*PID:495b div2
*Auth:Jonariguez
*****************
a mod x = b -->a-b=k*x
领d=a-b，将及其分解，求出d的约数的个数，
然后这些约数中小于等于b的是不符合的，然后通过
dfs减去这些小于等于b的即可
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

vector<LL> prime,p;
bool vis[100001];
LL a,b,now,res,c[100];

void table(){
    LL i,j;
    for(i=2;i<100000;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(j=i*i;j<100000;j+=i) vis[j]=1;
        }
    }
}

void dfs(LL cur,LL sum){
   // if(cur==p.size()) return ;
    if(sum<=b || sum>a) res--;
    LL i;
    for(i=cur;i>=0;i--){
        if(c[i]==0) continue;
        c[i]--;
        dfs(i,sum*p[i]);
        c[i]++;
    }
}

int main()
{
    LL i,j;
    table();
    while(scanf("%I64d%I64d",&a,&b)!=EOF){
        if(a==1 && b==0){
            printf("1\n");continue;
        }
        if(a==b){
            printf("infinity\n");continue;
        }
        if(a-b==1 || a<b){
            printf("0\n");continue;
        }
        LL d=a-b;now=d;
        p.clear();
        for(i=0;i<prime.size() && prime[i]*prime[i]<=d;i++){
            if(d%prime[i]==0){
                LL cnt=0;
                while(d%prime[i]==0){
                    cnt++;d/=prime[i];
                }
                c[p.size()]=cnt;
                p.push_back(prime[i]);
            }
        }
        if(d!=1){
            c[p.size()]=1;p.push_back(d);
        }
        res=1;
        for(i=0;i<p.size();i++)
            res*=(c[i]+1);
       // printf("%I64d\n",res);
        dfs((LL)(p.size()-1),1LL);
        printf("%I64d\n",res);
    }
    return 0;
}
