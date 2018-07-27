/****************
*PID:uva11542
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

const int maxn=100+10;
typedef int Matrix[maxn][maxn];

bool vis[510];
vector<int> prime;
Matrix A;

int table(){
    int i,j;
    for(i=2;i<=500;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(j=i*2;j<=500;j+=i)
                vis[j]=1;
        }
    }
    return (int)prime.size();
}

int Gauss(Matrix A,int m,int n){
    int i=0,j=0,k,r,u;
    while(i<m && j<n){
        r=i;
        for(k=i;k<m;k++)
            if(A[k][j]){
                r=k;break;
            }
        if(A[r][j]){
            if(r!=i)
                for(k=0;k<=n;k++) swap(A[r][k],A[i][k]);
            for(u=i+1;u<m;u++)
                if(A[u][j])
                    for(k=j;k<=n;k++) A[u][k]^=A[i][k]; //这里写k=j也会AC
            i++;
        }
        j++;
    }
    return i;
}

int main()
{
    int i,j,n,m,T;
    m=table();
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(A,0,sizeof(A));
        int large=0;
        for(i=0;i<n;i++){
            LL x;
            scanf("%lld",&x);
            for(j=0;j<m;j++){
                LL t=(LL)prime[j];
                while(x%t==0){
                    large=max(large,j);
                    x/=t;A[j][i]^=1;
                }
            }
        }
        int cnt=Gauss(A,large+1,n);
        printf("%lld\n",(1LL<<(n-cnt))-1);
    }
    return 0;
}

