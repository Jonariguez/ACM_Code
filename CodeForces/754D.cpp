/****************
*PID:754D
*Auth:Jonariguez
*****************
将区间hash一下，就和某度之星的题非常相似了，就是
要再记录一下可行解。
可行解：只需在求解答案res时记录重叠区间的左右端点，
输出可行解时对n个区间for一遍，输出前k个覆盖答案区间的区间即可
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("d",&x,&y)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#define MP make_pair
#define X first
#define Y second
#define PI acos(-1.0)
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

const int maxn=300000+10;
const int MOD=1e9+7;

int L[maxn],R[maxn],l[maxn],r[maxn];
vector<int> p,vec[maxn*2];
multiset<int> S;

int cmp(int i,int j){
    if(L[i]==L[j])
        return R[i]<R[j];
    return L[i]<L[j];
}

int getHash(int x){
    return upper_bound(p.begin(),p.end(),x)-p.begin();
}

int main()
{
    int i,j,n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        p.clear();
        for(i=1;i<=n;i++){
            scanf("%d%d",&L[i],&R[i]);
            p.push_back(L[i]);
            p.push_back(R[i]);
        }
        sort(p.begin(),p.end());
        p.erase(unique(p.begin(),p.end()),p.end());
        int m=p.size();
        for(i=0;i<=m;i++){
            vec[i].clear();
        }
        for(i=1;i<=n;i++){
            l[i]=getHash(L[i]);
            r[i]=getHash(R[i]);
            vec[l[i]].push_back(r[i]);
        }
        int res=0,ansl=0,ansr=0;
        S.clear();
        for(i=1;i<=m;i++){
            for(j=0;j<vec[i].size();j++)
                S.insert(vec[i][j]);
            while(S.size()>k)
                S.erase(S.begin());
            if(S.size()==k && *S.begin()>=i){
                int temp=p[*S.begin()-1]-p[i-1]+1;
                if(res<temp){
                    res=temp;
                    ansr=p[*S.begin()-1];ansl=p[i-1];
                }
            }
        }
        printf("%d\n",res);
        if(res==0)
            for(i=1;i<=k;i++)
                printf("%d%c",i," \n"[i==k]);
        else {
            for(i=1;k;i++){
                if(L[i]<=ansl && R[i]>=ansr){
                    printf("%d ",i);k--;
                }
            }
            puts("");
        }
    }
    return 0;
}

