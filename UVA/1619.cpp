/****************
*PID:uva1619
*Auth:Jonariguez
*****************
类似于uva1642(第十章例题最后一个)
超时
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
int a[maxn],L[maxn],R[maxn];
ll sum[maxn];

void init(int n){
    int i,t;
    stack<int> s;
    a[0]=a[n+1]=-1000006;
    s.push(0);
 //   printf("???\n");
    for(i=1;i<=n;i++){
        while(a[s.top()]>=a[i])
            s.pop();
        L[i]=s.top();
        s.push(i);
    }
    while(!s.empty())
        s.pop();
    s.push(n+1);
    for(i=n;i>=1;i--){
        while(a[s.top()]>=a[i])
            s.pop();
        R[i]=s.top();
        s.push(i);
    }
}


ll get_sum(int l,int r){
    return sum[r]-sum[l-1];
}

int main()
{
    int i,j,n,kc=0;
    while(scanf("%d",&n)!=EOF){
        if(kc++)
            printf("\n");
        sum[0]=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        init(n);
        ll res=-1;
        int l,r;
        for(i=1;i<=n;i++){
            ll t=get_sum(L[i]+1,R[i]-1);
            if(t*a[i]>res){
                res=t*a[i];
                l=L[i]+1;r=R[i]-1;
            }
        }
        if(res==0)
            printf("0\n1 1\n");     //注意
        else
            printf("%lld\n%d %d\n",res,l,r);
    }
    return 0;
}


