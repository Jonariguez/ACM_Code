#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
const int MOD=1e9+7;
int a[maxn],L[maxn],R[maxn];

vector<int> v[10005];

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<=10000;i++) v[i].clear();
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            v[a[i]].push_back(i);
        }
        for(i=1;i<=10000;i++)
            sort(v[i].begin(),v[i].end());
        memset(L,0,sizeof(L));
        fill(R,R+n+1,n+1);
        for(i=1;i<=n;i++){
            int t=a[i];
            for(j=1;j*j<=t;j++)
                if(t%j==0){
                    if(v[j].size()>0){
                        int idx1=lower_bound(v[j].begin(),v[j].end(),i)-v[j].begin(); //搜到位置一定不会等于i
                        int idx2=upper_bound(v[j].begin(),v[j].end(),i)-v[j].begin();
                        if(idx1>0) L[i]=max(L[i],v[j][idx1-1]);
                        if(idx2<v[j].size()) R[i]=min(R[i],v[j][idx2]);
                    }
                    int k=t/j;
                    if(j!=k && v[k].size()>0){
                        int idx1=lower_bound(v[k].begin(),v[k].end(),i)-v[k].begin(); //搜到位置一定不会等于i
                        int idx2=upper_bound(v[k].begin(),v[k].end(),i)-v[k].begin();
                        if(idx1>0) L[i]=max(L[i],v[k][idx1-1]);
                        if(idx2<v[k].size()) R[i]=min(R[i],v[k][idx2]);
                    }
                }
        }
     /*   for(i=1;i<=n;i++)
            printf("L[%d]=%d,R[%d]=%d\n",i,L[i],i,R[i]);
        printf("\n");*/
        long long res=0;
        for(i=1;i<=n;i++)
            res+=(ll)((ll)i-L[i])*(R[i]-i)%MOD;
        printf("%lld\n",res%MOD);
    }
    return 0;
}

