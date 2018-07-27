/****************
*PID:uva714
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

const int maxn=500+10;
LL a[maxn];
int n,k;
vector<int> res,ans;

bool C(LL x){
    int cnt=1;
    LL sum=0;
    for(int i=1;i<=n;i++){
        if(sum+a[i]>x){
            sum=a[i];cnt++;
        }else sum+=a[i];
    }
    return cnt<=k;
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        LL l=1,r=0;
        for(i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
            r+=a[i];
            l=max(l,a[i]);
        }
        while(l<r){
            LL m=(l+r)/2;
            if(C(m))
                r=m;
            else l=m+1;
        }
      //  printf("%I64d\n",l);
        res.clear();
        LL sum=0;
        int cnt=0;
        for(i=n;i>=1;i--){
            if(sum+a[i]>l){
                res.push_back(cnt);sum=a[i];cnt=1;
            }else {
                sum+=a[i];cnt++;
            }
        }
        res.push_back(cnt);
        reverse(res.begin(),res.end());
       // for(i=0;i<res.size();i++) printf("%d ",res[i]);
      //  puts("");
        k-=res.size();
        int first=0;j=0;
        for(i=1;i<=n;i++){
            if(first) printf(" ");
            first=1;
            if(i==n){
                printf("%d",a[i]);continue;
            }
            if(res[j]==1){
                printf("%d",a[i]);printf(" /");j++;continue;
            }
            if(k){
                printf("%d",a[i]);
                printf(" /");
                res[j]--;k--;
            }else {
                res[j]--;
                printf("%d",a[i]);
                if(res[j]==0){
                    j++;printf(" /");
                }
            }
        }
        printf("\n");
    }
    return 0;
}

