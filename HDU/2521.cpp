#include <stdio.h>
#include <string.h>

const int maxn=5000+10;
int res[maxn],cnt[maxn];

int cal(int n){
    int i,t,c,sum=1;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            c=0;
            while(n%i==0){
                c++;n/=i;
            }
            sum*=(c+1);
        }
    }
    if(n!=1)
        sum*=2;
    return sum;
}

void solve(){
    int n,p,c,t,i;
    for(n=2;n<=5000;n++)
        res[n]=cal(n);
    res[1]=1;
}

int main()
{
    int i,T,a,b,ans,index;
    solve();
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&a,&b);
        ans=res[a];index=a;
        for(i=a;i<=b;i++)
            if(ans<res[i]){
                ans=res[i];index=i;
            }
        printf("%d\n",index);
    }
    return 0;
}
