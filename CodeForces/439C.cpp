/****************
*PID:439c div2
*Auth:Jonariguez
*****************
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
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;
int a[maxn];
vector<int> odd,eve;

int main()
{
    int i,j,n,k,p;
    while(scanf("%d%d%d",&n,&k,&p)!=EOF){
        odd.clear();eve.clear();
        int ji=0,ou=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]&1){
                ji++;odd.push_back(a[i]);
            }else {
                ou++;eve.push_back(a[i]);
            }
        }
        int q=k-p;
        if(ji<q || ji>=q && (ji-q)&1){
            puts("NO");continue;
        }
        if(q+(ji-q)/2+ou<k){
            puts("NO");continue;
        }
        PY;
        if(p==0){
            for(i=0;i<k-1;i++)
                printf("1 %d\n",odd[i]);
            printf("%d",n-k+1);
            printf(" %d",odd[k-1]);
            for(i=0;i<eve.size();i++)
                printf(" %d",eve[i]);
            puts("");continue;
        }else if(q==0){
            if(eve.size()>=k-1){
                for(i=0;i<k-1;i++)
                    printf("1 %d\n",eve[i]);
                printf("%d",n-k+1);
                for(;i<eve.size();i++)
                    printf(" %d",eve[i]);
                for(i=0;i<odd.size();i++)
                    printf(" %d",odd[i]);
                puts("");continue;
            }else {
                int cnt=0;
                for(i=0;i<eve.size();i++){
                    printf("1 %d\n",eve[i]);
                    cnt++;
                }
                int temp=eve.size();
                j=0;
                for(i=temp;i<=k-1;i++){
                    printf("2 ");
                  //  for(;j<odd.size();j+=2)
                    printf("%d %d\n",odd[j],odd[j+1]);
                    cnt+=2;j+=2;
                }
                if(n-cnt>0){
                    printf("%d",n-cnt);
                    for(;j<odd.size();j++)
                        printf(" %d",odd[j]);
                    puts("");
                }
                continue;
            }
        }
        int cnt=0;
        for(i=0;i<q;i++){
            printf("1 %d\n",odd[i]);
            cnt++;
        }
        if(ou<p){
            for(i=0;i<eve.size();i++){
                printf("1 %d\n",eve[i]);
                cnt++;
            }
            int c=eve.size()+1;
            for(i=q;c<p && i<odd.size();i+=2){
                printf("2 %d %d\n",odd[i],odd[i+1]);
                c++;cnt+=2;
            }
            printf("%d",n-cnt);
            for(;i<odd.size();i++)
                printf(" %d",odd[i]);
            puts("");
        }else {
            for(i=0;i<p-1;i++){
                printf("1 %d\n",eve[i]);cnt++;
            }
            printf("%d",n-cnt);
            for(;i<eve.size();i++)
                printf(" %d",eve[i]);
            for(i=q;i<odd.size();i++)
                printf(" %d",odd[i]);
            puts("");
        }
    }
    return 0;
}

/*
8 4 4
1 1 1 1 1 1 1 1

*/




