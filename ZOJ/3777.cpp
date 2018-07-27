/****************
*PID:zoj3777
*Auth:Jonariguez
*****************
*/
#include<stdio.h>
#include <string.h>
#include <vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=12;
int n,m,P[maxn][maxn];
int p[maxn+1];
vector<int> vec1[(1<<maxn)],vec2[(1<<maxn)];
int fact[30];

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int i,j,T;
    fact[0]=1;
    for(i=1;i<=12;i++)
        fact[i]=fact[i-1]*i;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&P[i][j]);
        if(n==1){               //n=1要特判
            if(P[0][0]<m)
                puts("No solution");
            else printf("1/1\n");
            continue;
        }
        int mask,ALL=(1<<n)-1,cnt,sum;
        int n1=n/2;
        for(mask=1;mask<=ALL;mask++){   //暴力计算vec1[mask]
            cnt=0;sum=0;
            for(i=0;i<n;i++)
                if((mask>>i)&1) cnt++;
            if(cnt!=n1) continue;       //位置不是n1个则continue
            vec1[mask].clear();
            for(i=1;i<=n1;i++)
                p[i]=i;
            do{
                sum=0;
                j=1;
                for(i=0;i<n;i++){
                    if((mask>>i)&1){
                        sum+=P[p[j]-1][i];  //注意题目编号也是从0~n-1的
                        j++;
                    }
                }
                vec1[mask].push_back(sum);
            }while(next_permutation(p+1,p+n1+1));   //n/2道题在n/2个位置上的全排
        }
        int n2=n-n1;
        for(mask=1;mask<=ALL;mask++){   //暴力计算vec2[mask]
            cnt=0;sum=0;
            for(i=0;i<n;i++)
                if((mask>>i)&1) cnt++;
            if(cnt!=n2) continue;
            vec2[mask].clear();
            for(i=1;i<=n2;i++)
                p[i]=i;
            do{
                sum=0;
                j=1;
                for(i=0;i<n;i++){
                    if((mask>>i)&1){
                        sum+=P[p[j]+n1-1][i];   //注意这里要+n1
                        j++;
                    }
                }
                vec2[mask].push_back(sum);
            }while(next_permutation(p+1,p+n2+1));
            sort(vec2[mask].begin(),vec2[mask].end());  //后面要二分，所以这里要排序。
        }
        int res=0;
        for(mask=1;mask<=ALL;mask++){
            cnt=0;
            int t=0;
            for(i=0;i<n;i++){
                if((mask>>i)&1) cnt++;
                else t|=(1<<i);         //mask为vec1的状态，t为mask的反状态，即vec1[mask]-->vec2[t]
            }
            if(cnt!=n1) continue;
            for(i=0;i<vec1[mask].size();i++){
                int v=vec1[mask][i];
                res+=vec2[t].size()-(lower_bound(vec2[t].begin(),vec2[t].end(),m-v)-vec2[t].begin());
            }
        }
        if(!res)
            puts("No solution");
        else {
            int g=gcd(res,fact[n]);
            printf("%d/%d\n",fact[n]/g,res/g);
        }
    }
    return 0;
}




